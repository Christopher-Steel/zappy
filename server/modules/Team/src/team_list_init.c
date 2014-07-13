/*
** team_list_init.c for zappy in /home/launoi_a/tmp/PSU_2013_zappy/server/modules/Team
** 
** Made by allyriane.launois
** Login   <launoi_a@epitech.net>
** 
** Started on  Sun Jul 13 19:00:23 2014 allyriane.launois
** Last update Sun Jul 13 19:00:32 2014 allyriane.launois
*/

#include "set_parameter.h"
#include "print_warning.h"
#include "server.h"
#include "team.h"

void	team_list_init(void)
{
  char	*name;

  if (g_server.team_list != NULL)
    return ;
  g_server.team_list = list_create();
  name = strtok(g_server.param.team_names, "\n");
  while (name)
    {
      team_create(++g_server.param.team_max_id, name);
      name = strtok(NULL, "\n");
    }
  free(g_server.param.team_names);
  if (g_server.team_list->size < 1)
    {
      printf_warning("No team names specified, defaulting to \"%s\"",
		     DEFAULT_N);
      team_create(++g_server.param.team_max_id, DEFAULT_N);
    }
}
