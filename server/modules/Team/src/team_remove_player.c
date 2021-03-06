/*
** team_remove_player.c for zappy in /home/launoi_a/tmp/PSU_2013_zappy/server/modules/Team
** 
** Made by allyriane.launois
** Login   <launoi_a@epitech.net>
** 
** Started on  Sun Jul 13 19:00:36 2014 allyriane.launois
** Last update Sun Jul 13 19:19:24 2014 Valentin
*/

#include "team.h"

void		team_remove_player(t_player *player)
{
  t_team	*team;

  team = player->team;
  list_remove(team->members, player, false);
  team_update_max_level(team);
}

void		team_remove_egg(t_egg *egg, bool hatch)
{
  t_team	*team;

  team = egg->team;
  list_remove(team->members, egg, false);
  if (!hatch)
    --(team->free_slots);
}
