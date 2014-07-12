#include "egg.h"
#include "event.h"
#include "player.h"
#include "print_error.h"
#include "print_log.h"
#include "server.h"
#include "world.h"

static bool	egg_register_hatch(t_egg *egg)
{
  t_event	*event;

  if ((event = event_create((t_event_handler *)egg, &egg_hatch, 600, NULL)))
    return (false);
  else
    {
      gs_event_add(event);
      return (true);
    }
}

bool		player_fork(void *pl,
			    __attribute__ ((unused))void *unused)
{
  t_player	*player;
  int		index;
  t_egg		*new_egg;

  player = (t_player *)pl;
  if ((new_egg = egg_create(g_server.info.nb_clients, player->team)) == NULL)
    return (false);
  team_add_egg(new_egg, player->team->name);
  new_egg->pos = player->pos;
  index = player->pos.x + (player->pos.y * gs_get_map_width());
  if (egg_register_hatch(new_egg) == false
      || !add_egg(new_egg, index))
    {
      egg_destroy(new_egg);
      return (print_perror("failed to spawn egg"));
    }
  printf_log("New egg at %d/%d", player->pos.x, player->pos.y);
  client_write_to(player->client, "ok");
  return (true);
}
