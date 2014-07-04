
#include <stdlib.h>

#include "network_client.h"
#include "Graph_PO.h"

bool	graph_PO(t_player *player, char *cmd)
{
  if (client_write_to(palyer->client, cmd))
    {
      free(cmd);
      return (true);
    }
  //fre cmd ??
  return (false);
}
