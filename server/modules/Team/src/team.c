
#define	 _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "team.h"
#include "list.h"
#include "set_parameter.h"

t_team		*team_create(int id, char *name)
{
  t_team	*team;

  if ((team = malloc(sizeof(t_team))) == NULL)
    {
      print_perror("malloc");
      return (NULL);
    }
  team->id = id;
  if (name == NULL)
    asprintf(&team->name, "%s%d", DEFAULT_N, id);
  else
    if (!(team->name = strdup(name)))
      print_perror("strdup");
  team->members = list_create();
  team->eggs = list_create();
  team->max_level = 0;
  team->free_slots = g_param.slots;
  list_push_front(g_server.team_list, team);
  return (team);
};

void		team_destroy(t_team *team)
{
  list_destroy(team->members);
  list_destroy(team->eggs);
  free(team->name);
  free(team);
}