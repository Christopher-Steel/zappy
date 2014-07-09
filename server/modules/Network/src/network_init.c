#include "print_log.h"
#include "network.h"
#include "server.h"

bool		network_init(int port)
{
  t_sockpool	*pool;
  int		rc;

  print_log("Initializing network...");
  pool = &g_server.network.pool;
  pool->listener = -1;
  if ((rc = tcp_sock_passive_init(&pool->listener, port, LISTEN_Q_SIZE)))
    printf_log("Network initialized. Listening on port %d", port);
  else
    print_log("Failed to initialize network.");
  return (rc);
}
