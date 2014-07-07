#include "world.h"

static bool	check_condition(t_elevation *cond, t_player *player)
{
  t_world	*world;
  unsigned int	pos;

  world = g_server.world;
  pos = player->pos.x + (player->pos.y * gs_get_map_width());
  if (world->cell[pos].list_player->size >= cond->nb_player &&
      world->cell[pos].res[LINEMATE] >= cond->res[LINEMATE] &&
      world->cell[pos].res[DERAUMERE] >= cond->res[DERAUMERE] &&
      world->cell[pos].res[SIBUR] >= cond->res[SIBUR] &&
      world->cell[pos].res[MENDIANE] >= cond->res[MENDIANE] &&
      world->cell[pos].res[PHIRAS] >= cond->res[PHIRAS] &&
      world->cell[pos].res[THYSTAME] >= cond->res[THYSTAME])
    {
      player->is_incant = true;
      return (true);
    }
  return (false);
}

bool		player_incantation(t_player *player,
				   __attribute__ ((unused))char *unused)
{
  t_list	*elev;
  t_node	*node;

  elev = g_server.elevation;
  if (!player->is_incant)
    while (elev->nodes != NULL)
      {
	node = elev->nodes;
	if (((t_elevation *)node->data)->lvl_min == player->level)
	  return (check_condition((t_elevation *)node->data, player));
	elev->nodes = elev->nodes->next;
      }
  return (false);
}
