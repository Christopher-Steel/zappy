
#include "print_error.h"
#include "print_log.h"
#include "team.h"

static t_team		*find_team(char *team_name)
{
  t_node	*node;

  node = g_server.team_list->nodes;
  while (node && strcmp(((t_team *)(node->data))->name, team_name) != 0)
    node = node->next;
  if (node)
    return (node->data);
  return (NULL);
}

t_player	*team_create_player(char *team_name, t_client *client)
{
  t_team	*team;
  t_player	*player;

  if (!(team = find_team(team_name)))
    {
      printf_error("\"%s\" is not a valid team name", team_name);
      return (NULL);
    }
  else if (team->free_slots <= 0)
    {
      printf_error("team \"%s\" has no free slot for a new player",
		   team->name);
      return (NULL);
    }
  if (!(player = spawn_player(client, team)))
    return (NULL);
  list_push_front(team->members, player);
  printf_log("Player %d joined team %s", player->id, team_name);
  player->team = team;
  return (player);
}
