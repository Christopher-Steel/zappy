/*
** sockpool_node_io.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Network/src/socket_pool
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:38:28 2014 Valentin
** Last update Sun Jul 13 19:38:28 2014 Valentin
*/

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
  if (node->closing && list_empty(&node->outbound)
      && ring_buf_empty(&node->write))
    client_shutdown(node);
  return (rc);
}
