/*
** player_expulse.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Player/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:13:12 2014 Valentin
** Last update Sun Jul 13 19:13:12 2014 Valentin
*/

#define _GNU_SOURCE

#include "graph_PI.h"
#include "print_log.h"
#include "server.h"
#include "world.h"

static bool	inform_expulsed_player(t_player *player, enum e_ori ori)
{
  static char	*tab[] =
    {
      "5713",
      "7135",
      "1357",
      "3571"
    };
  char		*dir;

  if (asprintf(&dir, "deplacement: %c", tab[player->ori][ori]) != -1)
    {
      client_write_to(player->client, dir);
      free(dir);
      return (true);
    }
  return (false);
}

static bool	expulsing(t_node *node, t_player *player,
			  unsigned int pos_init, t_vector vec_dest)
{
  t_player	*expulsed;
  unsigned int	pos_final;

  printf_log("player %d expulsant", player->id);
  pos_final = vec_dest.x + (vec_dest.y * gs_get_map_width());
  while (node != NULL)
    {
      if (node != NULL && ((t_player *)node->data)->id != player->id)
	{
	  expulsed = ((t_player *)node->data);
	  remove_player(expulsed->id, pos_init);
	  add_player(expulsed, pos_final);
	  node = node->next;
	  expulsed->pos = vec_dest;
	  if (!inform_expulsed_player(expulsed, player->ori))
	    return (false);
	}
      else
	node = node->next;
    }
  graph_for_each_1_arg(&graphic_pex, player);
  for (node = (g_server.world.cell[pos_init]).list_player.nodes;
       node; node = node->next)
    graph_for_each_1_arg(&graphic_ppo2, node->data);
  return (client_write_to(player->client, "ok"));
}

bool		player_expulse(void *pl,
			       __attribute__ ((unused))void *unused)
{
  t_player	*player;
  t_world	*world;
  t_node	*node;
  t_vector	vec_dest;
  t_vector	vec;
  unsigned int	pos_init;

  player = (t_player *)pl;
  world = &g_server.world;
  vec = get_vec_direction(player->ori);
  vec_dest = add_vector(player->pos, vec);
  vec_dest = wrap_vertical(vec_dest);
  vec_dest = wrap_horizontal(vec_dest);
  pos_init = player->pos.x + (player->pos.y * gs_get_map_width());
  node = world->cell[pos_init].list_player.nodes;
  if (world->cell[pos_init].list_player.size > 1)
    return (expulsing(node, player, pos_init, vec_dest));
  return (client_write_to(player->client, "ko"));
}
