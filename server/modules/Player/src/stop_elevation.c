#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>

#include "print_error.h"
#include "world.h"

static bool	send_results_to_players(t_player *player, t_node *node,
					bool up)
{
  t_node	*tmp;
  t_player	*pl;
  char		*str;

  tmp = node;
  if (asprintf(&str, "niveau actuel : %u",
	       player->level + (up ? 1 : 0)) == -1)
    {
      print_perror("failed to allocate level description");
      client_write_to(player->client, "ko");
      return (false);
    }
  while (tmp != NULL)
    {
      pl = (t_player *)node->data;
      if (pl->level == player->level)
	{
	  client_write_to(pl->client, str);
	  if (up)
	    ++pl->level;
	}
      tmp = tmp->next;
    }
  free(str);
  return (true);
}

bool		stop_elevation(void *pl,
			       __attribute__ ((unused))void *unused)
{
  t_player	*player;
  t_world	*world;
  t_node	*node;
  unsigned int	pos;

  player = (t_player *)pl;
  world = g_server.world;
  pos = player->pos.x + (player->pos.y * gs_get_map_width());
  node = world->cell[pos].list_player->nodes;
  if (check_condition(player, node, pos))
    {
      ressource_spreading(pos, player->level - 1);
      return (send_results_to_players(player, node, true));
    }
  return (send_results_to_players(player, node, false));
}
