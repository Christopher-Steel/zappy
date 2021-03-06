/*
** team.c for zappy in /home/launoi_a/tmp/PSU_2013_zappy/server/modules/Team
** 
** Made by allyriane.launois
** Login   <launoi_a@epitech.net>
** 
** Started on  Sun Jul 13 18:59:10 2014 allyriane.launois
** Last update Sun Jul 13 18:59:23 2014 allyriane.launois
*/

#define	 _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "print_error.h"
#include "print_log.h"
#include "server.h"
#include "team.h"

t_team		*team_create(int id, char *name)
{
  t_team	*team;

  if ((team = malloc(sizeof(t_team))) == NULL)
    {
      print_perror("failed to allocate new team");
      return (NULL);
    }
  team->id = id;
  if (name == NULL)
    asprintf(&team->name, "team%d", id);
  else if (!(team->name = strdup(name)))
    print_perror("strdup");
  team->members = list_create();
  team->eggs = list_create();
  team->max_level = 0;
  team->free_slots = g_server.param.slots;
  list_push_front(g_server.team_list, team);
  printf_log("Created team \"%s\"", name);
  return (team);
};

void		team_destroy(t_team *team)
{
  if (team->members)
    list_destroy(team->members, true);
  if (team->eggs)
    list_destroy(team->eggs, true);
  free(team->name);
  free(team);
}
