#include "world.h"

bool	stop_incantation(t_player *player, char *cmd)
{
  (void)cmd;
  player->is_incant = false;
  return (true);
}
