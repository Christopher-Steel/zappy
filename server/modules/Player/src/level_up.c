#include "world.h"

static void	ressource_spreading(unsigned int pos, t_world *world,
				    t_elevation *cond)
{
  unsigned int	i;
  unsigned int	rand_pos;
  unsigned int	quantity;

  i = 1;
  while (i < 7)
    {
      world->cell[pos].res[i] -= cond->res[i];
      quantity = 0;
      while (quantity < cond->res[i])
	{
	  rand_pos = rand() % world->size;
	  ++world->cell[rand_pos].res[i];
	  ++quantity;
	}
      ++i;
    }
}

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
      ++player->level;
      ressource_spreading(pos, world, cond);
      return (true);
    }
  return (false);
}

bool		level_up(t_player *player, char *cmd)
{
  t_list	*elev;
  t_node	*node;

  (void)cmd;
  elev = g_server.elevation;
  player->is_incant = false;
  if (player->is_incant)
    while (elev->nodes != NULL)
      {
	node = elev->nodes;
	if (((t_elevation *)node->data)->lvl_min == player->level)
	  return (check_condition((t_elevation *)node->data, player));
	elev->nodes = elev->nodes->next;
      }
  return (false);
}
