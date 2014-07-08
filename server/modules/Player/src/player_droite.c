#include "player.h"

bool			player_droite(t_player *player,
				      __attribute__ ((unused))char *unused)
{
  static enum e_ori	rot_ori[4] =
    {
      EAST,
      SOUTH,
      WEST,
      NORTH
    };

  player->ori = rot_ori[player->ori];
  return (true);
}
