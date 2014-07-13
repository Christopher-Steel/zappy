/*
** graphic_tna.c for zappy in /home/launoi_a/tmp/PSU_2013_zappy/server/modules/Graphic
** 
** Made by allyriane.launois
** Login   <launoi_a@epitech.net>
** 
** Started on  Sun Jul 13 18:45:19 2014 allyriane.launois
** Last update Sun Jul 13 18:45:49 2014 allyriane.launois
*/

#define _GNU_SOURCE
#include <stdio.h>

#include "graphic.h"
#include "print_error.h"
#include "server.h"

static void	find_team_name(void *data, void *arg)
{
  char		*tmp;
  char		**answer;
  t_team	*team;

  team = (t_team *)data;
  answer = (char **)arg;

  if (asprintf(&tmp, "tna %s", team->name) == -1)
    {
      print_error("failed to alloc new graphic message");
      return ;
    }
  if (!(*answer = realloc(*answer, sizeof(char) * (strlen(tmp) + 1))))
    {
      free(tmp);
      print_error("failed to allocate new graphic message");
      return ;
    }
  *answer = strcat(*answer, tmp);
  free(tmp);
}

bool	graphic_tna(t_graphic *graphic, __attribute__ ((unused))char *cmd)
{
  char	*answer;
  bool	success;

  answer = NULL;
  list_for_each_arg(g_server.team_list, &find_team_name, &answer);
  if (!answer)
    {
      graphic_smg_KO(graphic);
      return (false);
    }
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}
