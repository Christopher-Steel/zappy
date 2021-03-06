/*
** sockpool_node_create.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Network/src/socket_pool
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:40:07 2014 Valentin
** Last update Sun Jul 13 19:40:07 2014 Valentin
*/

#include <stdlib.h>

#include "handshaker.h"
#include "print_error.h"
#include "socket_pool.h"

t_sockpool_node		*sockpool_node_create(t_sock sock)
{
  t_sockpool_node	*new_node;

  if ((new_node = malloc(sizeof(*new_node))) == NULL)
    print_perror("failed to create new socket pool node");
  else
    {
      new_node->socket = sock;
      new_node->closing = false;
      new_node->ip = NULL;
      new_node->port = 0;
      ring_buf_ctor(&new_node->read);
      ring_buf_ctor(&new_node->write);
      new_node->inbound.size = 0;
      new_node->outbound.size = 0;
      new_node->receiver = (t_receiver *)handshaker_create(new_node);
    }
  return (new_node);
}
