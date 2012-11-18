/* Generated by the protocol buffer compiler.  DO NOT EDIT! */

/* Do not generate deprecated warnings for self */
#ifndef PROTOBUF_C_NO_DEPRECATED
#define PROTOBUF_C_NO_DEPRECATED
#endif

#include "src/messages.pb-c.h"
void   header__init
                     (Header         *message)
{
  static Header init_value = HEADER__INIT;
  *message = init_value;
}
size_t header__get_packed_size
                     (const Header *message)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &header__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t header__pack
                     (const Header *message,
                      uint8_t       *out)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &header__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t header__pack_to_buffer
                     (const Header *message,
                      ProtobufCBuffer *buffer)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &header__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Header *
       header__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Header *)
     protobuf_c_message_unpack (&header__descriptor,
                                allocator, len, data);
}
void   header__free_unpacked
                     (Header *message,
                      ProtobufCAllocator *allocator)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &header__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   ticket__init
                     (Ticket         *message)
{
  static Ticket init_value = TICKET__INIT;
  *message = init_value;
}
size_t ticket__get_packed_size
                     (const Ticket *message)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &ticket__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t ticket__pack
                     (const Ticket *message,
                      uint8_t       *out)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &ticket__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t ticket__pack_to_buffer
                     (const Ticket *message,
                      ProtobufCBuffer *buffer)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &ticket__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Ticket *
       ticket__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Ticket *)
     protobuf_c_message_unpack (&ticket__descriptor,
                                allocator, len, data);
}
void   ticket__free_unpacked
                     (Ticket *message,
                      ProtobufCAllocator *allocator)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &ticket__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   addr_discover__init
                     (AddrDiscover         *message)
{
  static AddrDiscover init_value = ADDR_DISCOVER__INIT;
  *message = init_value;
}
size_t addr_discover__get_packed_size
                     (const AddrDiscover *message)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &addr_discover__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t addr_discover__pack
                     (const AddrDiscover *message,
                      uint8_t       *out)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &addr_discover__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t addr_discover__pack_to_buffer
                     (const AddrDiscover *message,
                      ProtobufCBuffer *buffer)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &addr_discover__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
AddrDiscover *
       addr_discover__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (AddrDiscover *)
     protobuf_c_message_unpack (&addr_discover__descriptor,
                                allocator, len, data);
}
void   addr_discover__free_unpacked
                     (AddrDiscover *message,
                      ProtobufCAllocator *allocator)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &addr_discover__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   addr_discover_reply__init
                     (AddrDiscoverReply         *message)
{
  static AddrDiscoverReply init_value = ADDR_DISCOVER_REPLY__INIT;
  *message = init_value;
}
size_t addr_discover_reply__get_packed_size
                     (const AddrDiscoverReply *message)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &addr_discover_reply__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t addr_discover_reply__pack
                     (const AddrDiscoverReply *message,
                      uint8_t       *out)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &addr_discover_reply__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t addr_discover_reply__pack_to_buffer
                     (const AddrDiscoverReply *message,
                      ProtobufCBuffer *buffer)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &addr_discover_reply__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
AddrDiscoverReply *
       addr_discover_reply__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (AddrDiscoverReply *)
     protobuf_c_message_unpack (&addr_discover_reply__descriptor,
                                allocator, len, data);
}
void   addr_discover_reply__free_unpacked
                     (AddrDiscoverReply *message,
                      ProtobufCAllocator *allocator)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &addr_discover_reply__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   data__init
                     (Data         *message)
{
  static Data init_value = DATA__INIT;
  *message = init_value;
}
size_t data__get_packed_size
                     (const Data *message)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &data__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t data__pack
                     (const Data *message,
                      uint8_t       *out)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &data__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t data__pack_to_buffer
                     (const Data *message,
                      ProtobufCBuffer *buffer)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &data__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Data *
       data__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Data *)
     protobuf_c_message_unpack (&data__descriptor,
                                allocator, len, data);
}
void   data__free_unpacked
                     (Data *message,
                      ProtobufCAllocator *allocator)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &data__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   find_successor__init
                     (FindSuccessor         *message)
{
  static FindSuccessor init_value = FIND_SUCCESSOR__INIT;
  *message = init_value;
}
size_t find_successor__get_packed_size
                     (const FindSuccessor *message)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &find_successor__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t find_successor__pack
                     (const FindSuccessor *message,
                      uint8_t       *out)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &find_successor__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t find_successor__pack_to_buffer
                     (const FindSuccessor *message,
                      ProtobufCBuffer *buffer)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &find_successor__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
FindSuccessor *
       find_successor__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (FindSuccessor *)
     protobuf_c_message_unpack (&find_successor__descriptor,
                                allocator, len, data);
}
void   find_successor__free_unpacked
                     (FindSuccessor *message,
                      ProtobufCAllocator *allocator)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &find_successor__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   find_successor_reply__init
                     (FindSuccessorReply         *message)
{
  static FindSuccessorReply init_value = FIND_SUCCESSOR_REPLY__INIT;
  *message = init_value;
}
size_t find_successor_reply__get_packed_size
                     (const FindSuccessorReply *message)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &find_successor_reply__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t find_successor_reply__pack
                     (const FindSuccessorReply *message,
                      uint8_t       *out)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &find_successor_reply__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t find_successor_reply__pack_to_buffer
                     (const FindSuccessorReply *message,
                      ProtobufCBuffer *buffer)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &find_successor_reply__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
FindSuccessorReply *
       find_successor_reply__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (FindSuccessorReply *)
     protobuf_c_message_unpack (&find_successor_reply__descriptor,
                                allocator, len, data);
}
void   find_successor_reply__free_unpacked
                     (FindSuccessorReply *message,
                      ProtobufCAllocator *allocator)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &find_successor_reply__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   stabilize__init
                     (Stabilize         *message)
{
  static Stabilize init_value = STABILIZE__INIT;
  *message = init_value;
}
size_t stabilize__get_packed_size
                     (const Stabilize *message)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &stabilize__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t stabilize__pack
                     (const Stabilize *message,
                      uint8_t       *out)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &stabilize__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t stabilize__pack_to_buffer
                     (const Stabilize *message,
                      ProtobufCBuffer *buffer)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &stabilize__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Stabilize *
       stabilize__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Stabilize *)
     protobuf_c_message_unpack (&stabilize__descriptor,
                                allocator, len, data);
}
void   stabilize__free_unpacked
                     (Stabilize *message,
                      ProtobufCAllocator *allocator)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &stabilize__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   stabilize_reply__init
                     (StabilizeReply         *message)
{
  static StabilizeReply init_value = STABILIZE_REPLY__INIT;
  *message = init_value;
}
size_t stabilize_reply__get_packed_size
                     (const StabilizeReply *message)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &stabilize_reply__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t stabilize_reply__pack
                     (const StabilizeReply *message,
                      uint8_t       *out)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &stabilize_reply__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t stabilize_reply__pack_to_buffer
                     (const StabilizeReply *message,
                      ProtobufCBuffer *buffer)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &stabilize_reply__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
StabilizeReply *
       stabilize_reply__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (StabilizeReply *)
     protobuf_c_message_unpack (&stabilize_reply__descriptor,
                                allocator, len, data);
}
void   stabilize_reply__free_unpacked
                     (StabilizeReply *message,
                      ProtobufCAllocator *allocator)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &stabilize_reply__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   notify__init
                     (Notify         *message)
{
  static Notify init_value = NOTIFY__INIT;
  *message = init_value;
}
size_t notify__get_packed_size
                     (const Notify *message)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &notify__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t notify__pack
                     (const Notify *message,
                      uint8_t       *out)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &notify__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t notify__pack_to_buffer
                     (const Notify *message,
                      ProtobufCBuffer *buffer)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &notify__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Notify *
       notify__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Notify *)
     protobuf_c_message_unpack (&notify__descriptor,
                                allocator, len, data);
}
void   notify__free_unpacked
                     (Notify *message,
                      ProtobufCAllocator *allocator)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &notify__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   ping__init
                     (Ping         *message)
{
  static Ping init_value = PING__INIT;
  *message = init_value;
}
size_t ping__get_packed_size
                     (const Ping *message)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &ping__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t ping__pack
                     (const Ping *message,
                      uint8_t       *out)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &ping__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t ping__pack_to_buffer
                     (const Ping *message,
                      ProtobufCBuffer *buffer)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &ping__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Ping *
       ping__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Ping *)
     protobuf_c_message_unpack (&ping__descriptor,
                                allocator, len, data);
}
void   ping__free_unpacked
                     (Ping *message,
                      ProtobufCAllocator *allocator)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &ping__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   pong__init
                     (Pong         *message)
{
  static Pong init_value = PONG__INIT;
  *message = init_value;
}
size_t pong__get_packed_size
                     (const Pong *message)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &pong__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t pong__pack
                     (const Pong *message,
                      uint8_t       *out)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &pong__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t pong__pack_to_buffer
                     (const Pong *message,
                      ProtobufCBuffer *buffer)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &pong__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Pong *
       pong__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Pong *)
     protobuf_c_message_unpack (&pong__descriptor,
                                allocator, len, data);
}
void   pong__free_unpacked
                     (Pong *message,
                      ProtobufCAllocator *allocator)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &pong__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
static const ProtobufCFieldDescriptor header__field_descriptors[3] =
{
  {
    "version",
    1,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_UINT32,
    PROTOBUF_C_OFFSETOF(Header, has_version),
    PROTOBUF_C_OFFSETOF(Header, version),
    NULL,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "type",
    2,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    PROTOBUF_C_OFFSETOF(Header, type),
    NULL,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "payload",
    3,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_BYTES,
    0,   /* quantifier_offset */
    PROTOBUF_C_OFFSETOF(Header, payload),
    NULL,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned header__field_indices_by_name[] = {
  2,   /* field[2] = payload */
  1,   /* field[1] = type */
  0,   /* field[0] = version */
};
static const ProtobufCIntRange header__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 3 }
};
const ProtobufCMessageDescriptor header__descriptor =
{
  PROTOBUF_C_MESSAGE_DESCRIPTOR_MAGIC,
  "Header",
  "Header",
  "Header",
  "",
  sizeof(Header),
  3,
  header__field_descriptors,
  header__field_indices_by_name,
  1,  header__number_ranges,
  (ProtobufCMessageInit) header__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor ticket__field_descriptors[2] =
{
  {
    "time",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    PROTOBUF_C_OFFSETOF(Ticket, time),
    NULL,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "hash",
    2,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_BYTES,
    0,   /* quantifier_offset */
    PROTOBUF_C_OFFSETOF(Ticket, hash),
    NULL,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned ticket__field_indices_by_name[] = {
  1,   /* field[1] = hash */
  0,   /* field[0] = time */
};
static const ProtobufCIntRange ticket__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 2 }
};
const ProtobufCMessageDescriptor ticket__descriptor =
{
  PROTOBUF_C_MESSAGE_DESCRIPTOR_MAGIC,
  "Ticket",
  "Ticket",
  "Ticket",
  "",
  sizeof(Ticket),
  2,
  ticket__field_descriptors,
  ticket__field_indices_by_name,
  1,  ticket__number_ranges,
  (ProtobufCMessageInit) ticket__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor addr_discover__field_descriptors[1] =
{
  {
    "ticket",
    1,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_BYTES,
    PROTOBUF_C_OFFSETOF(AddrDiscover, has_ticket),
    PROTOBUF_C_OFFSETOF(AddrDiscover, ticket),
    NULL,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned addr_discover__field_indices_by_name[] = {
  0,   /* field[0] = ticket */
};
static const ProtobufCIntRange addr_discover__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor addr_discover__descriptor =
{
  PROTOBUF_C_MESSAGE_DESCRIPTOR_MAGIC,
  "AddrDiscover",
  "AddrDiscover",
  "AddrDiscover",
  "",
  sizeof(AddrDiscover),
  1,
  addr_discover__field_descriptors,
  addr_discover__field_indices_by_name,
  1,  addr_discover__number_ranges,
  (ProtobufCMessageInit) addr_discover__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor addr_discover_reply__field_descriptors[2] =
{
  {
    "ticket",
    1,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_BYTES,
    PROTOBUF_C_OFFSETOF(AddrDiscoverReply, has_ticket),
    PROTOBUF_C_OFFSETOF(AddrDiscoverReply, ticket),
    NULL,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "addr",
    2,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_BYTES,
    0,   /* quantifier_offset */
    PROTOBUF_C_OFFSETOF(AddrDiscoverReply, addr),
    NULL,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned addr_discover_reply__field_indices_by_name[] = {
  1,   /* field[1] = addr */
  0,   /* field[0] = ticket */
};
static const ProtobufCIntRange addr_discover_reply__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 2 }
};
const ProtobufCMessageDescriptor addr_discover_reply__descriptor =
{
  PROTOBUF_C_MESSAGE_DESCRIPTOR_MAGIC,
  "AddrDiscoverReply",
  "AddrDiscoverReply",
  "AddrDiscoverReply",
  "",
  sizeof(AddrDiscoverReply),
  2,
  addr_discover_reply__field_descriptors,
  addr_discover_reply__field_indices_by_name,
  1,  addr_discover_reply__number_ranges,
  (ProtobufCMessageInit) addr_discover_reply__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const uint32_t data__ttl__default_value = 32;
static const protobuf_c_boolean data__last__default_value = 0;
static const ProtobufCFieldDescriptor data__field_descriptors[4] =
{
  {
    "id",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_BYTES,
    0,   /* quantifier_offset */
    PROTOBUF_C_OFFSETOF(Data, id),
    NULL,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "ttl",
    2,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_UINT32,
    PROTOBUF_C_OFFSETOF(Data, has_ttl),
    PROTOBUF_C_OFFSETOF(Data, ttl),
    NULL,
    &data__ttl__default_value,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "last",
    3,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_BOOL,
    PROTOBUF_C_OFFSETOF(Data, has_last),
    PROTOBUF_C_OFFSETOF(Data, last),
    NULL,
    &data__last__default_value,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "data",
    4,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_BYTES,
    0,   /* quantifier_offset */
    PROTOBUF_C_OFFSETOF(Data, data),
    NULL,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned data__field_indices_by_name[] = {
  3,   /* field[3] = data */
  0,   /* field[0] = id */
  2,   /* field[2] = last */
  1,   /* field[1] = ttl */
};
static const ProtobufCIntRange data__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 4 }
};
const ProtobufCMessageDescriptor data__descriptor =
{
  PROTOBUF_C_MESSAGE_DESCRIPTOR_MAGIC,
  "Data",
  "Data",
  "Data",
  "",
  sizeof(Data),
  4,
  data__field_descriptors,
  data__field_indices_by_name,
  1,  data__number_ranges,
  (ProtobufCMessageInit) data__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor find_successor__field_descriptors[4] =
{
  {
    "ticket",
    1,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_BYTES,
    PROTOBUF_C_OFFSETOF(FindSuccessor, has_ticket),
    PROTOBUF_C_OFFSETOF(FindSuccessor, ticket),
    NULL,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "ttl",
    2,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_UINT32,
    PROTOBUF_C_OFFSETOF(FindSuccessor, has_ttl),
    PROTOBUF_C_OFFSETOF(FindSuccessor, ttl),
    NULL,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "addr",
    3,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_BYTES,
    0,   /* quantifier_offset */
    PROTOBUF_C_OFFSETOF(FindSuccessor, addr),
    NULL,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "port",
    4,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    PROTOBUF_C_OFFSETOF(FindSuccessor, port),
    NULL,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned find_successor__field_indices_by_name[] = {
  2,   /* field[2] = addr */
  3,   /* field[3] = port */
  0,   /* field[0] = ticket */
  1,   /* field[1] = ttl */
};
static const ProtobufCIntRange find_successor__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 4 }
};
const ProtobufCMessageDescriptor find_successor__descriptor =
{
  PROTOBUF_C_MESSAGE_DESCRIPTOR_MAGIC,
  "FindSuccessor",
  "FindSuccessor",
  "FindSuccessor",
  "",
  sizeof(FindSuccessor),
  4,
  find_successor__field_descriptors,
  find_successor__field_indices_by_name,
  1,  find_successor__number_ranges,
  (ProtobufCMessageInit) find_successor__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor find_successor_reply__field_descriptors[3] =
{
  {
    "ticket",
    1,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_BYTES,
    PROTOBUF_C_OFFSETOF(FindSuccessorReply, has_ticket),
    PROTOBUF_C_OFFSETOF(FindSuccessorReply, ticket),
    NULL,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "addr",
    2,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_BYTES,
    0,   /* quantifier_offset */
    PROTOBUF_C_OFFSETOF(FindSuccessorReply, addr),
    NULL,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "port",
    3,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    PROTOBUF_C_OFFSETOF(FindSuccessorReply, port),
    NULL,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned find_successor_reply__field_indices_by_name[] = {
  1,   /* field[1] = addr */
  2,   /* field[2] = port */
  0,   /* field[0] = ticket */
};
static const ProtobufCIntRange find_successor_reply__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 3 }
};
const ProtobufCMessageDescriptor find_successor_reply__descriptor =
{
  PROTOBUF_C_MESSAGE_DESCRIPTOR_MAGIC,
  "FindSuccessorReply",
  "FindSuccessorReply",
  "FindSuccessorReply",
  "",
  sizeof(FindSuccessorReply),
  3,
  find_successor_reply__field_descriptors,
  find_successor_reply__field_indices_by_name,
  1,  find_successor_reply__number_ranges,
  (ProtobufCMessageInit) find_successor_reply__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor stabilize__field_descriptors[2] =
{
  {
    "addr",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_BYTES,
    0,   /* quantifier_offset */
    PROTOBUF_C_OFFSETOF(Stabilize, addr),
    NULL,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "port",
    2,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    PROTOBUF_C_OFFSETOF(Stabilize, port),
    NULL,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned stabilize__field_indices_by_name[] = {
  0,   /* field[0] = addr */
  1,   /* field[1] = port */
};
static const ProtobufCIntRange stabilize__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 2 }
};
const ProtobufCMessageDescriptor stabilize__descriptor =
{
  PROTOBUF_C_MESSAGE_DESCRIPTOR_MAGIC,
  "Stabilize",
  "Stabilize",
  "Stabilize",
  "",
  sizeof(Stabilize),
  2,
  stabilize__field_descriptors,
  stabilize__field_indices_by_name,
  1,  stabilize__number_ranges,
  (ProtobufCMessageInit) stabilize__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor stabilize_reply__field_descriptors[2] =
{
  {
    "addr",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_BYTES,
    0,   /* quantifier_offset */
    PROTOBUF_C_OFFSETOF(StabilizeReply, addr),
    NULL,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "port",
    2,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    PROTOBUF_C_OFFSETOF(StabilizeReply, port),
    NULL,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned stabilize_reply__field_indices_by_name[] = {
  0,   /* field[0] = addr */
  1,   /* field[1] = port */
};
static const ProtobufCIntRange stabilize_reply__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 2 }
};
const ProtobufCMessageDescriptor stabilize_reply__descriptor =
{
  PROTOBUF_C_MESSAGE_DESCRIPTOR_MAGIC,
  "StabilizeReply",
  "StabilizeReply",
  "StabilizeReply",
  "",
  sizeof(StabilizeReply),
  2,
  stabilize_reply__field_descriptors,
  stabilize_reply__field_indices_by_name,
  1,  stabilize_reply__number_ranges,
  (ProtobufCMessageInit) stabilize_reply__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor notify__field_descriptors[0] =
{
};
static const unsigned notify__field_indices_by_name[] = {
};
#define notify__number_ranges NULL
const ProtobufCMessageDescriptor notify__descriptor =
{
  PROTOBUF_C_MESSAGE_DESCRIPTOR_MAGIC,
  "Notify",
  "Notify",
  "Notify",
  "",
  sizeof(Notify),
  0,
  notify__field_descriptors,
  notify__field_indices_by_name,
  0,  notify__number_ranges,
  (ProtobufCMessageInit) notify__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor ping__field_descriptors[2] =
{
  {
    "ticket",
    1,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_BYTES,
    PROTOBUF_C_OFFSETOF(Ping, has_ticket),
    PROTOBUF_C_OFFSETOF(Ping, ticket),
    NULL,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "time",
    2,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_FIXED64,
    0,   /* quantifier_offset */
    PROTOBUF_C_OFFSETOF(Ping, time),
    NULL,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned ping__field_indices_by_name[] = {
  0,   /* field[0] = ticket */
  1,   /* field[1] = time */
};
static const ProtobufCIntRange ping__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 2 }
};
const ProtobufCMessageDescriptor ping__descriptor =
{
  PROTOBUF_C_MESSAGE_DESCRIPTOR_MAGIC,
  "Ping",
  "Ping",
  "Ping",
  "",
  sizeof(Ping),
  2,
  ping__field_descriptors,
  ping__field_indices_by_name,
  1,  ping__number_ranges,
  (ProtobufCMessageInit) ping__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor pong__field_descriptors[2] =
{
  {
    "ticket",
    1,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_BYTES,
    PROTOBUF_C_OFFSETOF(Pong, has_ticket),
    PROTOBUF_C_OFFSETOF(Pong, ticket),
    NULL,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "time",
    2,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_FIXED64,
    0,   /* quantifier_offset */
    PROTOBUF_C_OFFSETOF(Pong, time),
    NULL,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned pong__field_indices_by_name[] = {
  0,   /* field[0] = ticket */
  1,   /* field[1] = time */
};
static const ProtobufCIntRange pong__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 2 }
};
const ProtobufCMessageDescriptor pong__descriptor =
{
  PROTOBUF_C_MESSAGE_DESCRIPTOR_MAGIC,
  "Pong",
  "Pong",
  "Pong",
  "",
  sizeof(Pong),
  2,
  pong__field_descriptors,
  pong__field_indices_by_name,
  1,  pong__number_ranges,
  (ProtobufCMessageInit) pong__init,
  NULL,NULL,NULL    /* reserved[123] */
};