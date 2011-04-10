#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include "chord.h"
#include "dispatcher.h"
#include "messages.pb-c.h"

int process_addr_discover(Header *header, ChordPacketArgs *args,
						  AddrDiscover *msg, Node *from)
{
	Server *srv = args->srv;
	CHORD_DEBUG(5, print_process(srv, "process_addr_discover", &from->id,
								 &from->addr, from->port));

	send_addr_discover_reply(srv, msg->ticket.data, &from->addr, from->port);
	return CHORD_NO_ERROR;
}

int process_addr_discover_reply(Header *header, ChordPacketArgs *args,
								AddrDiscoverReply *msg, Node *from)
{
	Server *srv = args->srv;
	CHORD_DEBUG(5, print_process(srv, "process_addr_discover_repl", &from->id,
								 &from->addr, from->port));

	if (!verify_ticket(&srv->ticket_key, msg->ticket.data, "c6s",
					   CHORD_ADDR_DISCOVER, &from->addr, from->port))
		return CHORD_INVALID_TICKET;

	if (IN6_IS_ADDR_UNSPECIFIED(&srv->node.addr)) {
		v6_addr_set(&srv->node.addr, msg->addr.data);
		get_address_id(&srv->node.id, &srv->node.addr, srv->node.port);
		chord_update_range(srv, &srv->node.id, &srv->node.id);

		fprintf(stderr, "address: [%s]:%d\n", v6addr_to_str(&srv->node.addr),
			   srv->node.port);
		fprintf(stderr, "node id: ");
		print_chordID(&srv->node.id);
		fprintf(stderr, "\n");

		event_del(srv->discover_addr_event);

		struct timeval timeout;
		timeout.tv_sec = STABILIZE_PERIOD / 1000000UL;
		timeout.tv_usec = STABILIZE_PERIOD % 1000000UL;

		event_add(srv->stab_event, &timeout);
		event_active(srv->stab_event, EV_TIMEOUT, 1);
	}
	return CHORD_NO_ERROR;
}

Node *next_route_node(Server *srv, chordID *id, int last, int *next_is_last)
{
	Finger *pf, *sf;

	if (last && ((pf = pred_finger(srv)) != NULL)) {
		/* the previous hop N believes we are responsible for id,
		 * but we aren't. This means that our predecessor is
		 * a better successor for N. Just pass the packet to our
		 * predecessor. Note that ttl takes care of loops!
		 */
		*next_is_last = 1;
		return &pf->node;
	}

	if ((sf = succ_finger(srv)) != NULL) {
		if (is_between(id, &srv->node.id, &sf->node.id)
			|| equals(id, &sf->node.id)) {
			/* according to our info the successor should be responsible
				 * for id; send the packet to the successor.
			 */
			*next_is_last = 1;
			return &sf->node;
		}
	}

	/* send packet to the closest active predecessor (that we know about) */
	*next_is_last = 0;
	return closest_preceding_node(srv, id, FALSE);
}

int process_data(Header *header, ChordPacketArgs *args, Data *msg, Node *from)
{
	Server *srv = args->srv;
	chordID id;
	memcpy(id.x, msg->id.data, CHORD_ID_LEN);

	if (IN6_IS_ADDR_UNSPECIFIED(&srv->node.addr))
		return CHORD_ADDR_UNDISCOVERED;

	CHORD_DEBUG(3, print_process(srv, "process_data", &id, NULL, -1));

	if (--msg->ttl == 0) {
		print_two_chordIDs("TTL expired: data packet ", &id,
						   " dropped at node ", &srv->node.id, "\n");
		return CHORD_TTL_EXPIRED;
	}

	/* handle request locally? */
	if (chord_is_local(srv, &id)) {
		/* Upcall goes here... */
		fprintf(stderr, "id is local\n");
		//chord_deliver(len, data, from);
	}
	else {
		int next_is_last;
		Node *np = next_route_node(srv, &id, msg->last, &next_is_last);
		send_data(srv, next_is_last, msg->ttl, np, &id, msg->data.len,
				  msg->data.data);
	}
	return CHORD_NO_ERROR;
}

int process_fs(Header *header, ChordPacketArgs *args, FindSuccessor *msg,
			   Node *from)
{
	Server *srv = args->srv;
	Node *succ, *np;
	chordID reply_id;
	in6_addr reply_addr;
	ushort reply_port = msg->port;

	if (IN6_IS_ADDR_UNSPECIFIED(&srv->node.addr))
		return CHORD_ADDR_UNDISCOVERED;

	v6_addr_set(&reply_addr, msg->addr.data);
	get_address_id(&reply_id, &reply_addr, reply_port);

	CHORD_DEBUG(5, print_process(srv, "process_fs", &reply_id, &reply_addr,
								 reply_port));

	if (--msg->ttl == 0) {
		print_two_chordIDs("TTL expired: fix_finger packet ", &reply_id,
						   " dropped at node ", &srv->node.id, "\n");
		return CHORD_TTL_EXPIRED;
	}

	if (v6_addr_equals(&srv->node.addr, &reply_addr)
		&& srv->node.port == reply_port)
		return CHORD_NO_ERROR;

	if (succ_finger(srv) == NULL) {
		send_fs_reply(srv, msg->ticket.data, &reply_addr, reply_port,
					  &srv->node.addr, srv->node.port);
		return CHORD_NO_ERROR;
	}
	succ = &succ_finger(srv)->node;

	if (is_between(&reply_id, &srv->node.id, &succ->id) || equals(&reply_id,
																  &succ->id)) {
		send_fs_reply(srv, msg->ticket.data, &reply_addr, reply_port,
					  &succ->addr, succ->port);
	}
	else {
		np = closest_preceding_node(srv, &reply_id, FALSE);
		send_fs_forward(srv, msg->ticket.data, msg->ttl, &np->addr, np->port,
						&reply_addr, reply_port);
	}
	return CHORD_NO_ERROR;
}

int process_fs_reply(Header *header, ChordPacketArgs *args,
					 FindSuccessorReply *msg, Node *from)
{
	Server *srv = args->srv;
	int fnew;
	chordID id;

	if (IN6_IS_ADDR_UNSPECIFIED(&srv->node.addr))
		return CHORD_ADDR_UNDISCOVERED;

	in6_addr addr;
	memcpy(addr.s6_addr, msg->addr.data, 16);

	get_address_id(&id, &addr, msg->port);

	if (!verify_ticket(&srv->ticket_key, msg->ticket.data, "c", CHORD_FS))
		return CHORD_INVALID_TICKET;

	if (v6_addr_equals(&srv->node.addr, &addr) && srv->node.port == msg->port)
		return CHORD_NO_ERROR;

	CHORD_DEBUG(5, print_process(srv, "process_fs_repl", &id, &from->addr,
								 from->port));

	insert_finger(srv, &id, &addr, msg->port, &fnew);
	if (fnew == TRUE)
		send_ping(srv, &addr, msg->port, get_current_time());

	return CHORD_NO_ERROR;
}

int process_stab(Header *header, ChordPacketArgs *args, Stabilize *msg,
				 Node *from)
{
	Server *srv = args->srv;
	Finger *pred = pred_finger(srv);
	int		 fnew;
	chordID id;

	if (IN6_IS_ADDR_UNSPECIFIED(&srv->node.addr))
		return CHORD_ADDR_UNDISCOVERED;

	in6_addr addr;
	memcpy(addr.s6_addr, msg->addr.data, 16);

	get_address_id(&id, &addr, msg->port);

	CHORD_DEBUG(5, print_process(srv, "process_stab", &id, &addr, msg->port));

	insert_finger(srv, &id, &addr, msg->port, &fnew);

	// If we have a predecessor, tell the requesting node what it is.
	if (pred)
		send_stab_reply(srv, &addr, msg->port, &pred->node.addr,
						pred->node.port);
	return CHORD_NO_ERROR;
}

int process_stab_reply(Header *header, ChordPacketArgs *args,
					   StabilizeReply *msg, Node *from)
{
	Server *srv = args->srv;
	Finger *succ;
	int fnew;
	chordID id;

	if (IN6_IS_ADDR_UNSPECIFIED(&srv->node.addr))
		return CHORD_ADDR_UNDISCOVERED;

	in6_addr addr;
	memcpy(addr.s6_addr, msg->addr.data, 16);

	get_address_id(&id, &addr, msg->port);

	CHORD_DEBUG(5, print_process(srv, "process_stab_repl", &id, NULL, -1));

	// If we are our successor's predecessor, everything is fine, so do nothing.
	if (v6_addr_equals(&srv->node.addr, &addr) && srv->node.port == msg->port)
		return CHORD_NO_ERROR;

	// Otherwise, there is a better successor in between us and our current
	// successor. So we notify the in-between node that we should be its
	// predecessor.
	insert_finger(srv, &id, &addr, msg->port, &fnew);
	succ = succ_finger(srv);
	send_notify(srv, &succ->node.addr, succ->node.port);
	if (fnew == TRUE)
		send_ping(srv, &addr, msg->port, get_current_time());
	return CHORD_NO_ERROR;
}

int process_notify(Header *header, ChordPacketArgs *args, Notify *msg,
				   Node *from)
{
	Server *srv = args->srv;
	int fnew;

	if (IN6_IS_ADDR_UNSPECIFIED(&srv->node.addr))
		return CHORD_ADDR_UNDISCOVERED;

	CHORD_DEBUG(5, print_process(srv, "process_notify", &from->id, &from->addr,
								 from->port));

	// another node thinks that it should be our predecessor
	insert_finger(srv, &from->id, &from->addr, from->port, &fnew);
	if (fnew == TRUE)
		send_ping(srv, &from->addr, from->port, get_current_time());
	return CHORD_NO_ERROR;
}

int process_ping(Header *header, ChordPacketArgs *args, Ping *msg, Node *from)
{
	Server *srv = args->srv;
	int fnew;
	Finger *pred;

	if (IN6_IS_ADDR_UNSPECIFIED(&srv->node.addr))
		return CHORD_ADDR_UNDISCOVERED;

	CHORD_DEBUG(5, print_process(srv, "process_ping", &from->id, &from->addr,
								 from->port));

	insert_finger(srv, &from->id, &from->addr, from->port, &fnew);
	pred = pred_finger(srv);
	if (fnew == TRUE
		&& ((pred == NULL)
			|| (pred && is_between(&from->id, &pred->node.id,
								   &srv->node.id)))) {
		send_ping(srv, &from->addr, from->port, get_current_time());
	}

	send_pong(srv, msg->ticket.data, &from->addr, from->port, msg->time);

	return CHORD_NO_ERROR;
}

int process_pong(Header *header, ChordPacketArgs *args, Pong *msg, Node *from)
{
	Server *srv = args->srv;
	Finger *f, *pred, *newpred;
	ulong	 new_rtt;
	int		 fnew;

	if (IN6_IS_ADDR_UNSPECIFIED(&srv->node.addr))
		return CHORD_ADDR_UNDISCOVERED;

	if (!verify_ticket(&srv->ticket_key, msg->ticket.data, "c6sl", CHORD_PING,
					   &from->addr, from->port, msg->time))
		return CHORD_INVALID_TICKET;

	f = insert_finger(srv, &from->id, &from->addr, from->port, &fnew);
	if (!f)
		return CHORD_FINGER_ERROR;

	CHORD_DEBUG(5, print_process(srv, "process_pong", &from->id, &from->addr,
								 from->port));
	f->npings = 0;
	new_rtt = get_current_time() - msg->time; /* takes care of overlow */
	update_rtt(&f->rtt_avg, &f->rtt_dev, (long)new_rtt);

	pred = pred_finger(srv);
	activate_finger(srv, f); /* there is a two-way connectivity to this node */
	newpred = pred_finger(srv); /* check whether pred has changed, i.e.,
								 * f has became the new pred
								 */
	assert(newpred || (pred == newpred));

	if (pred != newpred)
		chord_update_range(srv, &newpred->node.id, &srv->node.id);

	return CHORD_NO_ERROR;
}

void process_error(Header *header, ChordPacketArgs *args, void *msg, Node *from,
				   int error)
{
	char *err_str;
	switch (error) {
	case CHORD_NO_ERROR:
		err_str = "no error";
		break;
	case CHORD_PROTOCOL_ERROR:
		err_str = "protocol error";
		break;
	case CHORD_TTL_EXPIRED:
		err_str = "time-to-live expired";
		break;
	case CHORD_INVALID_TICKET:
		err_str = "invalid ticket";
		break;
	case CHORD_ADDR_UNDISCOVERED:
		err_str = "received routing packet before address discovery";
		break;
	case CHORD_SELF_ORIGINATOR:
		err_str = "received packet from self";
		break;
	case CHORD_FINGER_ERROR:
		err_str = "finger error";
		break;
	default:
		err_str = "unknown error";
		break;
	}

	weprintf("dropping packet [type 0x%02x: %s] from %s:%hu (%s)", header->type,
			 dispatcher_get_packet_name(args->srv->dispatcher, header->type),
			 v6addr_to_str(&from->addr), from->port, err_str);
}
