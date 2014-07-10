#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>

#include "world.h"

bool		player_incantation(t_player *player,
				   __attribute__ ((unused))char *unused)
{
  char		*str;
  t_world	*world;
  t_node	*node;
  unsigned int	pos;

  world = g_server.world;
  pos = player->pos.x + (player->pos.y * gs_get_map_width());
  node = world->cell[pos].list_player->nodes;
  if (check_condition(player, node, pos))
    {
      client_write_to(player->client, "elevation en cours");
      return (true);
    }
  asprintf(&str, "niveau actuel : %u", player->level);
  client_write_to(player->client, str);
  free(str);
  return (false);
}
