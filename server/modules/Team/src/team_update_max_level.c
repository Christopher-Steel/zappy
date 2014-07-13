/*
** team_update_max_level.c for zappy in /home/launoi_a/tmp/PSU_2013_zappy/server/modules/Team
** 
** Made by allyriane.launois
** Login   <launoi_a@epitech.net>
** 
** Started on  Sun Jul 13 19:01:02 2014 allyriane.launois
** Last update Sun Jul 13 19:01:11 2014 allyriane.launois
*/

#include "team.h"

void		update_level(void *player, void *team)
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
