#include <unistd.h>

#include "network_client.h"
#include "print_log.h"
#include "server.h"

void	client_shutdown(t_client *client)
{
  printf_log("Client %s:%d disconnected", client->ip, client->port);
  close(client->socket);
  free(client->ip);
  if (client->receiver)
    client->receiver->destroy(client->receiver);
  list_clear(&client->inbound, true);
  list_clear(&client->outbound, true);
  list_remove(&g_server.network.pool.nodes, client, true);
}
