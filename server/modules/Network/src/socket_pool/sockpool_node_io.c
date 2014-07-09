#include <string.h>

#include "inject_buffer.h"
#include "network_client.h"
#include "print_debug.h"
#include "socket_pool.h"

int	sockpool_node_read(t_sockpool_node *node)
{
  char	*in_cmd;
  int	rc;

  in_cmd = NULL;
  rc = ring_buf_read(&node->read, node->socket);
  printf_debug("ring_buf_read [len: %d, head: %d, tail: %d, buf: %s]",
	       node->read.len, node->read.head, node->read.tail,
	       &node->read.buf[0]);
  while (node->closing == false
	 && ring_buf_pop_alloc(&node->read, &in_cmd) > 0)
    node->receiver->receive(node->receiver, in_cmd);
  return (rc);
}

int	sockpool_node_write(t_sockpool_node *node)
{
  int	rc;

  while (!list_empty(&node->outbound)
	 && injectbuf_ring_inject(list_front(&node->outbound), &node->write)
	 == true)
    list_pop_front(&node->outbound, true);
  rc = ring_buf_write(&node->write, node->socket);
  printf_debug("[%d] ring_buf_write [len: %d, head: %d, tail: %d, buf: %s]",
	       node->socket,
	       node->write.len, node->write.head, node->write.tail,
	       &node->write.buf[0]);
  if (node->closing && list_empty(&node->outbound)
      && ring_buf_empty(&node->write))
    client_shutdown(node);
  return (rc);
}
