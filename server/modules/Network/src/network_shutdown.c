/*
** network_shutdown.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Network/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:31:42 2014 Valentin
** Last update Sun Jul 13 19:31:43 2014 Valentin
*/

#include <stdlib.h>
#include <unistd.h>

#include "print_log.h"
#include "network.h"
#include "server.h"

static void		close_sock(void *data)
{
  t_sockpool_node	*node;

  node = (t_sockpool_node *)data;
  close(node->socket);
}

void	network_shutdown(void)
{
  print_log("Shutting down network services...");
  close(g_server.network.pool.listener);
  list_for_each(&g_server.network.pool.nodes, &close_sock);
  list_clear(&g_server.network.pool.nodes, true);
}
