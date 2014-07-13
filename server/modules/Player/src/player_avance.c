/*
** player_avance.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Player/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:05:43 2014 Valentin
** Last update Sun Jul 13 19:05:46 2014 Valentin
*/

#include	"graph_PI.h"
#include	"print_error.h"
#include	"print_log.h"
#include	"server.h"
#include	"world.h"

bool		player_avance(void *pl,
			      __attribute__ ((unused))void *unused)
{
  t_player	*player;
  t_vector	vec;
  int		pos_init;
  int		pos_final;

  player = (t_player *)pl;
  pos_init = player->pos.x + (player->pos.y * gs_get_map_width());
  vec = get_vec_direction(player->ori);
  player->pos.x += vec.x;
  player->pos.y += vec.y;
  player->pos = wrap_vertical(player->pos);
  player->pos = wrap_horizontal(player->pos);
  pos_final = player->pos.x + (player->pos.y * gs_get_map_width());
  remove_player(player->id, pos_init);
  add_player(player, pos_final);
  graph_for_each_1_arg(&graphic_ppo2, pl);
  return (client_write_to(player->client, "ok"));
}
