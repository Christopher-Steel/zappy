#include <string.h>

#include "inject_buffer.h"
#include "network_client.h"
#include "print_debug.h"
#include "socket_pool.h"

int	sockpool_node_read(t_sockpool_node *node)
{
  char	*in_cmd;
  int	rc;

  in_cmd = "";
  rc = ring_buf_read(&node->read, node->socket);
  while (node->closing == false
	 && ring_buf_pop_alloc(&node->read, &in_cmd) > 0)
    {
      printf_debug("read popped [%s][buffer: head:%d tail:%d len:%d data:%s]",
		   in_cmd, node->read.head, node->read.tail, node->read.len,
		   &node->read.buf[0]);
      node->receiver->receive(node->receiver, in_cmd);
    }
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
  if (node->closing && list_empty(&node->outbound)
      && ring_buf_empty(&node->write))
    client_shutdown(node);
  return (rc);
}
