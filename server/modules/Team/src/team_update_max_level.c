
#include "team.h"

void	update_level(void *player, void *team)
{
  t_team	*t;
  t_player	*p;

  t = (t_team *)team;
  p = (t_player *)player;
  if (t->max_level > p->level)
    t->max_level = p->level;
}

void	team_update_max_level(t_team *team)
{
  list_for_each_arg(team->members, &update_level, team);
}
