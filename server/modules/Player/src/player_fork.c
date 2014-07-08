#include "world.h"
#include "print_error.h"
#include "print_log.h"

bool	player_fork(t_player *player,
		    __attribute__ ((unused))char *unused)
{
  int	index;
  t_egg	*new_egg;

  if ((new_egg = egg_create(g_server.info.nb_clients, player->team)) == NULL)
    return (false);
  ++g_server.info.nb_clients;
  team_add_egg(new_egg, player->team->name);
  new_egg->pos = player->pos;
  index = player->pos.x + (player->pos.y * gs_get_map_width());
  if (!add_egg(new_egg, index))
    return (print_perror("failed to spawn egg"));
  printf_log("New egg at %d/%d", player->pos.x, player->pos.y);
  client_write_to(player->client, "ok");
  return (true);
}
