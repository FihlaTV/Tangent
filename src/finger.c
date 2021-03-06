#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "chord/chord.h"
#include "chord/finger.h"
#include "chord/util.h"

/* new_finger: allocate and initialize finger structure */
Finger *new_finger(Node *node)
{
	Finger *fp;

	/* allocate space for new finger */
	fp = emalloc(sizeof(Finger));
	fp->node = *node;
	fp->status = F_PASSIVE;
	fp->npings = 0;
	fp->next = fp->prev = NULL;
	fp->rtt_avg = fp->rtt_dev = 0;
	return fp;
}

/**********************************************************************/

Finger *succ_finger(ChordServer *srv)
{
	Finger *f;
	for (f = srv->head_flist; f; f = f->next) {
		if (f->status == F_ACTIVE)
			return f;
	}
	return NULL;
}

/**********************************************************************/

Finger *pred_finger(ChordServer *srv)
{
	Finger *f;
	for (f = srv->tail_flist; f; f = f->prev) {
		if (f->status == F_ACTIVE)
			return f;
	}
	return NULL;
}

/**********************************************************************/

/* closest_preceding_node: search table for highest predecessor of id */
/* closest_preceding_finger: search table for highest predecessor of id */

Finger *closest_preceding_finger(ChordServer *srv, chordID *id, int fall)
{
	Finger *f;
	for (f = srv->tail_flist; f; f = f->prev) {
		/* look only for active fingers; we do not know if we can
		 * reach the passive fingers
		 */
		if (fall || f->status == F_ACTIVE) {
			if (id_is_between(&f->node.id, &srv->node.id, id))
				return f;
		}
	}

	return NULL;
}

Node *closest_preceding_node(ChordServer *srv, chordID *id, int fall)
{
	Finger *f = closest_preceding_finger(srv, id, fall);

	if (f == NULL)
		return &srv->node;
	else
		return &f->node;
}

/**********************************************************************/

Finger *get_finger(ChordServer *srv, chordID *id, int *index)
{
	Finger *f;
	int i;
	for (f = srv->head_flist, i = 0; f; f = f->next, i++) {
		if (id_equals(id, &f->node.id)) {
			if (index != NULL)
				*index = i;
			return f;
		}
	}
	return NULL;
}

/* find the finger that has failed to respond to the greatest number of pings */
Finger *get_worst_passive_finger(ChordServer *srv)
{
	Finger *f;
	Finger *worst_finger = NULL;
	int npings_record = -1;

	for (f = srv->head_flist; f; f = f->next) {
		if (f->status == F_PASSIVE && f->npings > npings_record) {
			npings_record = f->npings;
			worst_finger = f;

			// stop searching if we've found the worst we can get
			if (npings_record >= PING_THRESH-1)
				return worst_finger;
		}
	}
	return worst_finger;
}

/**********************************************************************/

void fingerlist_insert(ChordServer *srv, Finger *f);

Finger *insert_finger(ChordServer *srv, chordID *id, in6_addr *addr, in_port_t port,
					  int *fnew)
{
	Node n;

	if (v6_addr_equals(&srv->node.addr, addr) && srv->node.port == port) {
		LogWarn("dropping finger request from ourself");
		return NULL;
	}

	int index;
	Finger *f = get_finger(srv, id, &index);

	if (f) {
		if (!v6_addr_equals(&f->node.addr, addr)) {
			StartLog(INFO);
			PartialLog("Finger for id ");
			print_chordID(clog_file_logger()->fp, &f->node.id);
			
			// be careful about v6addr_to_str() using static buffer
			PartialLog(" is already in list with different peer; replacing <%s, %d>", v6addr_to_str(&f->node.addr), f->node.port);
			PartialLog(" with <%s, %d>", v6addr_to_str(&f->node.addr), f->node.port);
			EndLog();
			
			v6_addr_copy(&f->node.addr, addr);
			f->node.port = port;
			f->rtt_avg = f->rtt_dev = 0;
			f->npings = 0;

			StartLog(INFO);
			PartialLog("\n");
			print_server(clog_file_logger()->fp, srv);
			EndLog();
		}
		else {
			/* f is already in the list. In this case,
			 * f is not refreshed, i.e., f->npings is not set to 0.
			 * Refreshing f here might preclude the ping procedure from removing
			 * f when it dies.
			 */
			StartLog(DEBUG);
			PartialLog("Finger for id ");
			print_chordID(clog_file_logger()->fp, &f->node.id);
			PartialLog(" is already in list with the given peer <%s, %d>", v6addr_to_str(&f->node.addr), f->node.port);
			EndLog();
		}
		
		*fnew = 0;
		return f;
	}

	// only hold onto a certain number of passive fingers, to avoid getting
	// DoS'd
	if (srv->num_passive_fingers >= MAX_PASSIVE_FINGERS) {
		Finger *worst_finger = get_worst_passive_finger(srv);
		assert(worst_finger);

		StartLog(DEBUG);
		PartialLog("Dropping passive finger for id ");
		print_chordID(clog_file_logger()->fp, &f->node.id);
		EndLog();

		remove_finger(srv, worst_finger);
	}

	srv->num_passive_fingers++;

	n.id = *id;
	v6_addr_copy(&n.addr, addr);
	n.port = port;

	Finger *new_f = new_finger(&n);
	fingerlist_insert(srv, new_f);

	StartLog(INFO);
	PartialLog("\n");
	print_server(clog_file_logger()->fp, srv);
	EndLog();

	*fnew = 1;
	return new_f;
}

void fingerlist_insert(ChordServer *srv, Finger *new_f)
{
	if (srv->head_flist == NULL)
		srv->head_flist = srv->tail_flist = new_f;
	else {
		Finger *prec_f = closest_preceding_finger(srv, &new_f->node.id, 1);
		if (prec_f == NULL) {
			new_f->next = srv->head_flist;
			new_f->prev = NULL;
			srv->head_flist->prev = new_f;
			srv->head_flist = new_f;
		}
		else {
			new_f->next = prec_f->next;
			if (prec_f->next)
				prec_f->next->prev = new_f;
			else
				srv->tail_flist = new_f;
			new_f->prev = prec_f;
			prec_f->next = new_f;
		}
	}
}

void activate_finger(ChordServer *srv, Finger *f)
{
	if (f->status == F_PASSIVE) {
		srv->num_passive_fingers--;
		f->status = F_ACTIVE;

		StartLog(INFO);
		PartialLog("\n");
		chord_print_circle(srv, clog_file_logger()->fp);
		EndLog();
	}
}

/**********************************************************************/

void remove_finger(ChordServer *srv, Finger *f)
{
	StartLog(DEBUG);
	PartialLog("Removing finger ");
	print_node(clog_file_logger()->fp, &f->node);
	EndLog();
	
	Finger *pred, *pf;

	if (f->status == F_PASSIVE)
		srv->num_passive_fingers--;

	pred = pred_finger(srv); /* remember to check whether pred changes */

	if ((srv->tail_flist != f) && (srv->head_flist != f)) {
		f->prev->next = f->next;
		f->next->prev = f->prev;
	}
	else {
		if (srv->head_flist == f) {
			srv->head_flist = f->next;
			if (f->next)
				f->next->prev = NULL;
		}
		if (srv->tail_flist == f) {
			srv->tail_flist = f->prev;
			if (f->prev)
				f->prev->next = NULL;
		}
	}

	pf = pred_finger(srv);
	if (pred != pf) {
		if (pf == NULL)
			chord_update_range(srv, &srv->node.id, &srv->node.id);
		else
			chord_update_range(srv, &pf->node.id, &srv->node.id);
	}

	StartLog(DEBUG);
	PartialLog("\n");
	print_server(clog_file_logger()->fp, srv);
	EndLog();
	
	free(f);
}

/**********************************************************************/

void free_finger_list(Finger *flist)
{
	Finger *f;

	while (flist) {
		f = flist;
		flist = flist->next;
		free(f);
	}
}
