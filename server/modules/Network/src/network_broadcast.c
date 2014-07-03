#include "network.h"
#include "server.h"

void		network_broadcast(char *msg)
{
  list_push_back(&g_server.network.pool.broadcast, msg);
}
