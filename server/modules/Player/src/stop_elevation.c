#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>

#include "world.h"

static void	level_up_all_player(t_player *player, t_node *node)
{
  t_node	*tmp;
  t_player	*pl;

  tmp = node;
  while (tmp != NULL)
    {
      pl = (t_player *)node->data;
      if (pl->level == player->level)
	++pl->level;
      tmp = tmp->next;
    }
}

static bool	inform_all_player(t_player *player, t_node *node)
{
  t_node	*tmp;
  t_player	*pl;
  char		*str;

  tmp = node;
  while (tmp != NULL)
    {
      pl = (t_player *)node->data;
      if (pl->level == player->level)
	{
	  if (asprintf(&str, "niveau actuel : %u", pl->level) != -1)
	    {
	      if (client_write_to(pl->client, str) == false)
		return (false);
	      free(str);
	    }
	  else
	    return (false);
	}
      tmp = tmp->next;
    }
  return (true);
}

bool		stop_elevation(t_player *player,
			       __attribute__ ((unused))char *unused)
{
  t_world	*world;
  t_node	*node;
  unsigned int	pos;

  world = g_server.world;
  pos = player->pos.x + (player->pos.y * gs_get_map_width());
  node = world->cell[pos].list_player->nodes;
  if (check_condition(player, node, pos))
    {
      level_up_all_player(player, node);
      ressource_spreading(pos, player->level - 1);
      return (true);
    }
  return (inform_all_player(player, node));
}
