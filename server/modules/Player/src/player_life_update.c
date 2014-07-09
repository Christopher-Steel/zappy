
#include "player.h"
#include "server.h"

static void	life_update_by_player(void *player)
{
  ((t_player *)player)->alive -= g_server.info.dtime;
  if (((t_player *)player)->alive <= 0)
    {
      if (((t_player *)player)->inventory[FOOD] <= 0)
	puts("is dead");
      else
	--(((t_player *)player)->inventory[FOOD]);
    }
}

static void	life_update_by_team(void *team)
{
  list_for_each(((t_team *)team)->members, &life_update_by_player);
}

void	player_life_update(void)
{
  list_for_each(g_server.team_list, &life_update_by_team);
}
