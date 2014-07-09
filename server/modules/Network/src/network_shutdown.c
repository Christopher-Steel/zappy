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
