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

void		ressource_spreading(unsigned int pos, int cond)
{
  unsigned int	i;
  unsigned int	rand_pos;
  unsigned int	quantity;
  t_world	*world;

  i = 1;
  world = g_server.world;
  while (i < 7)
    {
      world->cell[pos].res[i] -= g_cond[cond].res[i];
      quantity = 0;
      while (quantity < g_cond[i].res[i])
	{
	  rand_pos = rand() % world->size;
	  ++world->cell[rand_pos].res[i];
	  ++quantity;
	}
      ++i;
    }
}

bool	check_condition(t_player *player, t_node *node,
			unsigned int pos)
{
  t_world	*world;
  uint		lvl;

  world = g_server.world;
  lvl = player->level - 1;
  if (cnt_same_lvl(node, player->level) >= g_cond[lvl].nb_player &&
      world->cell[pos].res[LINEMATE] >= g_cond[lvl].res[LINEMATE] &&
      world->cell[pos].res[DERAUMERE] >= g_cond[lvl].res[DERAUMERE] &&
      world->cell[pos].res[SIBUR] >= g_cond[lvl].res[SIBUR] &&
      world->cell[pos].res[MENDIANE] >= g_cond[lvl].res[MENDIANE] &&
      world->cell[pos].res[PHIRAS] >= g_cond[lvl].res[PHIRAS] &&
      world->cell[pos].res[THYSTAME] >= g_cond[lvl].res[THYSTAME])
    return (true);
  return (false);
}
