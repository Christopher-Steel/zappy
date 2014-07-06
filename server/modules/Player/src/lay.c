#include "world.h"
#include "print_error.h"
#include "print_log.h"

bool	lay(t_player *player, char *cmd)
{
  int	pos;
  t_egg	*egg;

  (void)cmd;
  if ((egg = egg_create(g_server.info.nb_clients, player->team)) == NULL)
    return (print_perror("Malloc egg error\n"));
  ++g_server.info.nb_clients;
  team_add_egg(egg, player->team->name);
  egg->pos = player->pos;
  pos = player->pos.x + (player->pos.y * gs_get_map_width());
  if (!add_egg(egg, pos))
    return (print_perror("Cannot lay egg"));
  print_log("An egg was laid");
  return (true);
}
