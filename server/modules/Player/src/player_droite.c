#include "player.h"

bool			player_droite(void *pl,
				      __attribute__ ((unused))void *unused)
{
  static enum e_ori	rot_ori[4] =
    {
      EAST,
      SOUTH,
      WEST,
      NORTH
    };
  t_player		*player;

  player = (t_player *)pl;
  player->ori = rot_ori[player->ori];
  return (client_write_to(player->client, "ok"));
}
