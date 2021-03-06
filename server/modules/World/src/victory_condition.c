/*
** victory_condition.c for zappy in /home/launoi_a/tmp/PSU_2013_zappy/server/modules/World
** 
** Made by allyriane.launois
** Login   <launoi_a@epitech.net>
** 
** Started on  Sun Jul 13 19:18:39 2014 allyriane.launois
** Last update Sun Jul 13 19:19:22 2014 allyriane.launois
*/

#define _GNU_SOURCE

#include "print_log.h"
#include "server.h"
#include "world.h"
#include "graphic.h"
#include "graph_PI.h"

static int	cnt_player_lvl_max(t_node *team_player)
{
  int		nbr;

  nbr = 0;
  while (team_player)
    {
      if (((t_player *)team_player->data)->level == 8)
	++nbr;
      team_player = team_player->next;
    }
  return (nbr);
}

static bool	write_winner(t_team *team)
{
  char		*str;

  graph_for_each_1_arg(&graphic_seg, team->name);
  if (asprintf(&str, "Team %s wins", team->name) != -1)
    {
      print_log(str);
      free(str);
      return (true);
    }
  return (false);
}

bool		victory_condition_resolve(void)
{
  int		nbr;
  bool		is_play;
  t_node	*team;
  t_team	*team_info;
  t_node	*team_player;

  is_play = false;
  for (team = g_server.team_list->nodes; team; team = team->next)
    {
      team_info = ((t_team *)team->data);
      team_player = team_info->members->nodes;
      if (team_info->members->size > 0 ||
	  team_info->free_slots > 0)
	is_play = true;
      nbr = cnt_player_lvl_max(team_player);
      if (nbr >= 6)
	return (write_winner(team_info));
    }
  if (!is_play)
    {
      print_log("Everyone is dead, Game Over !");
      return (true);
    }
  return (false);
}
