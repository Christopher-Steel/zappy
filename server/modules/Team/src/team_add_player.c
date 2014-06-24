
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
  return (team_create(++g_param.team_max_id, team_name));
}

void	team_add_player(t_player *player, char *team_name)
{
  t_team	*team;

  team = find_team(team_name);
  list_push_front(team->members, player);
}
