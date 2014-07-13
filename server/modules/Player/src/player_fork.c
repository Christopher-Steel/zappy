#include "egg.h"
#include "event.h"
#include "graph_PI.h"
#include "player.h"
#include "print_error.h"
#include "print_log.h"
#include "server.h"
#include "world.h"

static bool	egg_register_hatch(t_egg *egg)
{
  t_event	*event;

  if ((event = event_create((t_event_handler *)egg, &egg_hatch, 600, NULL))
      == NULL)
    return (false);
  else
    {
      gs_event_add(event);
      return (true);
    }
}

bool		player_fork(void *player,
			    __attribute__ ((unused))void *unused)
{
  t_player		*pl;
  t_event_handler	*handler;
  t_pl_func		fn;

  pl = (t_player *)player;
  handler = (t_event_handler *)player;
  fn = player_fork_end;
  if ((pl->current_event = event_create(handler, fn, 42.0, NULL))
      == NULL)
    return (false);
  else
    {
      gs_event_add(pl->current_event);
      graph_for_each_1_arg(&graphic_pfk, player);
      return (true);
    }
}

bool		player_fork_end(void *pl,
			    __attribute__ ((unused))void *unused)
{
  void		**tab;
  t_player	*player;
  int		index;
  t_egg		*new_egg;

  player = (t_player *)pl;
  if ((new_egg = egg_create(g_server.info.nb_clients, player->team)) == NULL)
    return (false);
  team_add_egg(new_egg, player->team->name);
  new_egg->pos = player->pos;
  new_egg->player_lay = pl;
  index = player->pos.x + (player->pos.y * gs_get_map_width());
  if (egg_register_hatch(new_egg) == false
      || !add_egg(new_egg, index))
    {
      egg_destroy(new_egg);
      return (print_error("failed to spawn egg"));
    }
  printf_log("Created new egg %d spawned at position %d/%d", new_egg->id,
	     player->pos.x, player->pos.y);
  client_write_to(player->client, "ok");
  tab = mount_args(pl, new_egg);
  graph_for_each_2_args(&graphic_enw, tab);
  return (true);
}
