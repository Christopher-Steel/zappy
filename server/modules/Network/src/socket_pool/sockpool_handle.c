/*
** sockpool_handle.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Network/src/socket_pool
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:38:40 2014 Valentin
** Last update Sun Jul 13 19:38:53 2014 Valentin
*/

#include "network_client.h"
#include "print_error.h"
#include "print_log.h"
#include "socket_pool.h"

static bool	check_fd_set(t_sockpool *pool, t_sockpool_node *node,
			     fd_set *fds, int (*action)(t_sockpool_node *))
{
  int		rc;

  if (FD_ISSET(node->socket, fds))
    {
      --pool->nbset;
      if ((rc = action(node)) <= 0)
	{
	  if (rc == -1)
	    print_perror("network I/O error");
	  client_shutdown(node);
	  return (false);
	}
    }
  return (true);
}

static void	sockpool_handle_node(t_sockpool *pool,
				     t_sockpool_node *node)
{
  if (check_fd_set(pool, node, &pool->read_set, &sockpool_node_read))
    check_fd_set(pool, node, &pool->write_set, &sockpool_node_write);
}

void		sockpool_handle(t_sockpool *pool)
{
  t_node	*node;

  if (pool->nbset <= 0)
    return ;
  if (FD_ISSET(pool->listener, &pool->read_set))
    sockpool_add_client(pool, pool->listener);
  for (node = pool->nodes.nodes; pool->nbset > 0 && node;
       node = node->next)
    sockpool_handle_node(pool, (t_sockpool_node *)node->data);
}
