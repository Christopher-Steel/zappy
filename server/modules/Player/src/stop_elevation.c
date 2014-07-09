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

static void	ressource_spreading(unsigned int pos, t_world *world,
				    int cond)
{
  unsigned int	i;
  unsigned int	rand_pos;
  unsigned int	quantity;

  i = 1;
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

static bool	check_condition(t_player *player, t_node *node,
				t_world *world, unsigned int pos)
{
  uint		lvl;

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

static void	level_up_all_player(t_player *player, t_node *node)
{
  t_node	*tmp;
  t_player	*pl;

  tmp = node;
  while (tmp != NULL)
    {
      pl = (t_player *)node->data;
      if (pl->level == player->level)
	++((t_player *)node->data)->level;
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
	  asprintf(&str, "niveau actuel : %u", pl->level);
	  if (client_write_to(pl->client, str) == false)
	    return (false);
	  free(str);
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
  if (check_condition(player, node, world, pos))
    {
      level_up_all_player(player, node);
      ressource_spreading(pos, world, player->level - 1);
      return (true);
    }
  return (inform_all_player(player, node));
}
