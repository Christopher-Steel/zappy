
#include "list.h"
#include "team.h"

t_team		*find_team(char *team_name)
{
  char		*teams;
  t_node	*node;

  node = g_server.team_list->nodes;
  while (node && strcmp((t_team *)(node->data)->name, team_name) != 0)
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
    return (print_error("%s : unknown team name", team_name));
  list_push_front(team->members, player);
  player->team = team;
  return (true);
}

void		team_add_egg(t_egg *egg, char *team_name)
{
  t_team	*team;

  team = find_team(team_name);
  list_push_front(team->eggs, egg);
  egg->team = team;
}
