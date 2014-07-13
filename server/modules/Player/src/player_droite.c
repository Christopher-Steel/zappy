/*
** player_droite.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Player/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:12:58 2014 Valentin
** Last update Sun Jul 13 19:12:58 2014 Valentin
*/

#include "graph_PI.h"
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
  graph_for_each_1_arg(&graphic_ppo2, pl);
  return (client_write_to(player->client, "ok"));
}
