#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>

#include "player.h"
#include "world.h"

static bool		player_register_incant_end(t_player *player)
{
  t_event_handler	*handler;
  t_pl_func		fn;

  handler = (t_event_handler *)player;
  fn = &stop_elevation;
  if ((player->current_event = event_create(handler, fn, 300.0, NULL))
      == NULL)
    {
      // i highly doubt this is a good idea. Time will tell
      //      list_pop_front(&player->client->inbound, true);
      return (false);
    }
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
  world = g_server.world;
  pos = player->pos.x + (player->pos.y * gs_get_map_width());
  node = world->cell[pos].list_player->nodes;
  if (check_condition(player, node, pos))
    {
      client_write_to(player->client, "elevation en cours");
      if (player_register_incant_end(player))
	return (true);
    }
  asprintf(&str, "niveau actuel : %u", player->level);
  client_write_to(player->client, str);
  free(str);
  return (false);
}
