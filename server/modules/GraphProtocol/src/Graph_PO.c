
#include <stdlib.h>

#include "network_client.h"
#include "Graph_PO.h"

bool	graph_PO(t_player *player, char *cmd)
{
  if (client_write_to(player->client, cmd))
    {
      free(cmd);
      return (true);
    }
  free(cmd);
  return (false);
}
