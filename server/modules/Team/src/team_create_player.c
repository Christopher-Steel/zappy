#include <string.h>

#include "graph_PI.h"
#include "print_error.h"
#include "print_log.h"
#include "server.h"
#include "team.h"
#include "world.h"

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

static t_player	*spawn_from_egg(t_client *client, t_team *team)
{
  t_player	*player;
  t_node	*list_egg;
  t_egg		*egg;

  list_egg = team->eggs->nodes;
  while (list_egg != NULL)
    {
      egg = (t_egg *)list_egg->data;
      if (egg->is_hatches)
	{
	  if (!(player = spawn_pos_player(client, team, egg)))
	    return (NULL);
	  graph_for_each_1_arg(&graphic_ebo, egg);
	  graph_for_each_1_arg(&graphic_pnw, player);
	  list_remove(team->eggs, list_egg->data, true);
	  return (player);
	}
      list_egg = list_egg->next;
    }
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
  --(team->free_slots);
  if (!(player = spawn_from_egg(client, team)) &&
      !(player = spawn_player(client, team)))
    return (NULL);
  list_push_front(team->members, player);
  printf_log("Player %d joined team %s", player->id, team_name);
  return (player);
}
