/*
** team_add_player.c for zappy in /home/launoi_a/tmp/PSU_2013_zappy/server/modules/Team
** 
** Made by allyriane.launois
** Login   <launoi_a@epitech.net>
** 
** Started on  Sun Jul 13 18:58:47 2014 allyriane.launois
** Last update Sun Jul 13 18:59:04 2014 allyriane.launois
*/

#include "list.h"
#include "print_error.h"
#include "print_log.h"
#include "server.h"
#include "team.h"

static t_team	*find_team(char *team_name)
{
  t_node	*node;

  node = g_server.team_list->nodes;
  while (node && strcmp(((t_team *)(node->data))->name, team_name) != 0)
    node = node->next;
  if (node)
    return (node->data);
  return (NULL);
}

bool		team_add_player(t_player *player, char *team_name)
{
  t_team	*team;

  team = find_team(team_name);
  if (!team)
    return (printf_error("\"%s\" is not a valid team name", team_name));
  else if (team->free_slots <= 0)
    return (printf_error("team \"%s\" has no free slot for a new player",
			 team->name));
  list_push_front(team->members, player);
  printf_log("Player %d joined team %s", player->id, team_name);
  player->team = team;
  --(team->free_slots);
  return (true);
}

void		team_add_egg(t_egg *egg, char *team_name)
{
  t_team	*team;

  team = find_team(team_name);
  list_push_front(team->eggs, egg);
  egg->team = team;
}
