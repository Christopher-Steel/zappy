
#include <stdlib.h>

#include "network_client.h"
#include "AI_PO.h"

bool	AI_PO(t_player *player, char *cmd)
{
  if (client_write_to(player->client, cmd))
    {
      free(cmd);
      return (true);
    }
  free(cmd);
  return (false);
}
