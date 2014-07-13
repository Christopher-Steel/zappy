/*
** sockpool_fill_sets.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Network/src/socket_pool
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:39:03 2014 Valentin
** Last update Sun Jul 13 19:39:13 2014 Valentin
*/

#include <sys/socket.h>

#include "network_client.h"
#include "socket_pool.h"

static void	send_broadcast(void *data, void *arg)
{
  char		*msg;
  t_client	*dest;

  msg = (char *)data;
  dest = (t_client *)arg;
  client_write_to(dest, msg);
}

static void		add_sock(void *data, void *arg)
{
  t_sockpool_node	*node;
  t_sockpool		*pool;

  node = (t_sockpool_node *)data;
  pool = (t_sockpool *)arg;
  if (node->closing == false)
    FD_SET(node->socket, &pool->read_set);
  if (!(list_empty(&pool->broadcast)))
    list_for_each_arg(&pool->broadcast, &send_broadcast, node);
  if (!(list_empty(&node->outbound) && ring_buf_empty(&node->write)))
    FD_SET(node->socket, &pool->write_set);
  if ((uint)node->socket > pool->maxfd)
    pool->maxfd = node->socket;
}

void	sockpool_fill_sets(t_sockpool *pool)
{
  FD_ZERO(&pool->read_set);
  FD_ZERO(&pool->write_set);
  pool->maxfd = pool->listener;
  pool->nbset = 0;
  FD_SET(pool->listener, &pool->read_set);
  list_for_each_arg(&pool->nodes, &add_sock, pool);
  list_clear(&pool->broadcast, true);
}
