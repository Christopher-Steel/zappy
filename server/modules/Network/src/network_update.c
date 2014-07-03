#include "network.h"
#include "server.h"

void	network_update(void)
{
  sockpool_update(&g_server.network.pool);
}
