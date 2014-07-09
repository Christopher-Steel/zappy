#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>

#include "world.h"

static t_elevation	g_cond[] =
  {
    {{0, 1, 0, 0, 0, 0, 0}, 1, 1},
    {{0, 1, 1, 1, 0, 0, 0}, 2, 2},
    {{0, 2, 0, 1, 0, 2, 0}, 2, 3},
    {{0, 1, 1, 2, 0, 1, 0}, 4, 4},
    {{0, 1, 2, 1, 3, 0, 0}, 4, 5},
    {{0, 1, 2, 3, 0, 1, 0}, 6, 6},
    {{0, 2, 2, 2, 2, 2, 1}, 6, 7}
  };

static int	cnt_same_lvl(t_node *node, uint lvl)
{
  t_node	*tmp;
  int		nbr_player;

  tmp = node;
  nbr_player = 0;
  while (tmp != NULL)
    {
      if (((t_player *)node->data)->level == lvl)
	++nbr_player;
      tmp = tmp->next;
    }
  return (nbr_player);
}

bool		player_incantation(t_player *player,
				   __attribute__ ((unused))char *unused)
{
  char		*str;
  t_world	*world;
  t_node	*node;
  unsigned int	pos;
  unsigned int	lvl;

  world = g_server.world;
  pos = player->pos.x + (player->pos.y * gs_get_map_width());
  lvl = player->level - 1;
  node = world->cell[pos].list_player->nodes;
  if (cnt_same_lvl(node, player->level) >= g_cond[lvl].nb_player &&
      world->cell[pos].res[LINEMATE] >= g_cond[lvl].res[LINEMATE] &&
      world->cell[pos].res[DERAUMERE] >= g_cond[lvl].res[DERAUMERE] &&
      world->cell[pos].res[SIBUR] >= g_cond[lvl].res[SIBUR] &&
      world->cell[pos].res[MENDIANE] >= g_cond[lvl].res[MENDIANE] &&
      world->cell[pos].res[PHIRAS] >= g_cond[lvl].res[PHIRAS] &&
      world->cell[pos].res[THYSTAME] >= g_cond[lvl].res[THYSTAME])
    {
      client_write_to(player->client, "elevation en cours");
      return (true);
    }
  asprintf(&str, "niveau actuel : %u", player->level);
  client_write_to(player->client, str);
  free(str);
  return (false);
}
