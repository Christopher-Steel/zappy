#include <string.h>

#include "inject_buffer.h"
#include "network_client.h"
#include "print_debug.h"
#include "socket_pool.h"

void	sockpool_node_read(t_sockpool_node *node)
{
  char	*in_cmd;

  in_cmd = NULL;
  ring_buf_read(&node->read, node->socket);
  while (node->closing == false
	 && ring_buf_pop_alloc(&node->read, &in_cmd) > 0)
    node->receiver->receive(node->receiver, in_cmd);
}

void	sockpool_node_write(t_sockpool_node *node)
{
  while (!list_empty(&node->outbound)
	 && injectbuf_ring_inject(list_front(&node->outbound), &node->write)
	 == true)
    list_pop_front(&node->outbound, true);
  ring_buf_write(&node->write, node->socket);
  if (node->closing && list_empty(&node->outbound)
      && ring_buf_empty(&node->write))
    client_shutdown(node);
}
