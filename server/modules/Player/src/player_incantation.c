/*
** player_incantation.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Player/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:04:08 2014 Valentin
** Last update Sun Jul 13 19:04:09 2014 Valentin
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>

#include "graph_PI.h"
#include "player.h"
#include "server.h"
#include "world.h"

static bool		player_register_incant_end(t_player *player)
{
  t_event_handler	*handler;
  t_pl_func		fn;

  handler = (t_event_handler *)player;
  fn = &stop_elevation;
  if ((player->current_event = event_create(handler, fn, 300.0, NULL))
      == NULL)
      return (false);
  else
    {
      gs_event_add(player->current_event);
      return (true);
    }
}

bool		player_incantation(void *pl,
				   __attribute__ ((unused))void *unused)
{
  t_player	*player;
  char		*str;
  t_world	*world;
  t_node	*node;
  unsigned int	pos;

  player = (t_player *)pl;
  world = &g_server.world;
  pos = player->pos.x + (player->pos.y * gs_get_map_width());
  node = world->cell[pos].list_player.nodes;
  if (check_condition(player, node, pos))
    {
      client_write_to(player->client, "elevation en cours");
      if (player_register_incant_end(player))
	{
	  graph_incantation(&(world->cell[pos].list_player));
	  return (true);
	}
    }
  asprintf(&str, "niveau actuel : %u", player->level);
  client_write_to(player->client, str);
  free(str);
  return (false);
}
