#include "network_client.h"

void	client_close(t_client *client)
{
  client->closing = true;
}
