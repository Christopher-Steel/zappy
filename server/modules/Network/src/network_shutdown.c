#include <stdlib.h>
#include <unistd.h>

#include "print_log.h"
#include "network.h"
#include "server.h"

static void		close_sock(void *data)
{
  t_sockpool_node	*node;

  node = (t_sockpool_node *)data;
  if (data)
    free(data);
  close(node->socket);
}

void	network_shutdown(__attribute__ ((unused))int i,
			 __attribute__ ((unused))void *v)
{
  print_log("Shutting down network services");
  close(g_server.network.pool.listener);
  list_for_each(&g_server.network.pool.nodes, &close_sock);
}
