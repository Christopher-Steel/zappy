#include "player.h"

bool			player_gauche(t_player *player,
				      __attribute__ ((unused))char *unused)
{
  static enum e_ori	rot_ori[4] =
    {
      WEST,
      NORTH,
      EAST,
      SOUTH
    };

  player->ori = rot_ori[player->ori];
  return (true);
}
