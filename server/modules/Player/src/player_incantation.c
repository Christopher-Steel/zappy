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

bool		player_incantation(t_player *player,
				   __attribute__ ((unused))char *unused)
{
  /* t_node	*node; */

  /* while (elev->nodes != NULL) */
  /*   { */
  /*     node = elev->nodes; */
  /*     if (((t_elevation *)node->data)->lvl_min == player->level) */
  /* 	return (check_condition((t_elevation *)node->data, player)); */
  /*     elev->nodes = elev->nodes->next; */
  /*   } */
  /* return (false); */
  t_world	*world;
  unsigned int	pos;
  unsigned int	lvl;

  world = g_server.world;
  pos = player->pos.x + (player->pos.y * gs_get_map_width());
  lvl = player->level - 1;
  if (world->cell[pos].list_player->size >= g_cond[lvl].nb_player &&
      world->cell[pos].res[LINEMATE] >= g_cond[lvl].res[LINEMATE] &&
      world->cell[pos].res[DERAUMERE] >= g_cond[lvl].res[DERAUMERE] &&
      world->cell[pos].res[SIBUR] >= g_cond[lvl].res[SIBUR] &&
      world->cell[pos].res[MENDIANE] >= g_cond[lvl].res[MENDIANE] &&
      world->cell[pos].res[PHIRAS] >= g_cond[lvl].res[PHIRAS] &&
      world->cell[pos].res[THYSTAME] >= g_cond[lvl].res[THYSTAME])
    {
      player->is_incant = true;
      return (true);
    }
  return (false);
}
