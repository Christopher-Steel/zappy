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
  if (asprintf(&str, "L'equipe %s est vainqueur", team->name) != -1)
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
      print_log("The world is died, Game Over !");
      return (true);
    }
  return (false);
}
