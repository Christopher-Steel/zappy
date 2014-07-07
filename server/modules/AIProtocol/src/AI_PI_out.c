
#include <stdlib.h>

#include "network_client.h"
#include "AI_PI_out.h"

bool	AI_PI_out(t_player *player, char *cmd)
{
  if (client_write_to(player->client, cmd))
    {
      free(cmd);
      return (true);
    }
  free(cmd);
  return (false);
}
