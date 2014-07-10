
#include "team.h"

void		team_remove_player(t_player *player)
{
  t_team	*team;

  team = player->team;
  list_remove(team->members, player, false);
  team_update_max_level(team);
  --(team->free_slots);
}

void		team_remove_egg(t_egg *egg, bool hatch)
{
  t_team	*team;

  team = egg->team;
  list_remove(team->members, egg, false);
  if (!hatch)
    --(team->free_slots);
}
