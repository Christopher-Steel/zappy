#include "player.h"

static enum e_ori	g_rot_ori[4] =
  {
    EAST,
    SOUTH,
    WEST,
    NORTH
  };

bool		player_droite(t_player *player,
			      __attribute__ ((unused))char *unused)
{
  return (set_orientation(player, g_rot_ori[player->orientation.orientation]));
}
