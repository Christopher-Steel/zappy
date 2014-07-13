/*
** graphic_player_action.c for zappy in /home/launoi_a/tmp/PSU_2013_zappy/server/modules/Graphic
** 
** Made by allyriane.launois
** Login   <launoi_a@epitech.net>
** 
** Started on  Sun Jul 13 18:40:22 2014 allyriane.launois
** Last update Sun Jul 13 18:41:01 2014 allyriane.launois
*/

#define _GNU_SOURCE
#include <stdio.h>

#include "graphic.h"
#include "print_error.h"

bool	graphic_pex(t_graphic *graphic, void *player)
{
  char	*answer;
  bool	success = true;

  if (asprintf(&answer, "pex %d", ((t_player *)player)->id) == -1)
    return (print_error("failed to allocate new graphic message"));
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}

bool	graphic_pbc(t_graphic *graphic, void *player, void *msg)
{
  char	*answer;
  bool	success = true;

  if (asprintf(&answer, "pbc %d %s", ((t_player *)player)->id, (char *)msg)
      == -1)
    return (print_error("failed to allocate new graphic message"));
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}

bool	graphic_pic(t_graphic *graphic, void *players)
{
  char	*tmp;
  char	*answer;
  bool	success;
  int	i;

  i = -1;
  if (asprintf(&answer, "pic %d %d %d", (((t_player **)players)[0])->pos.x,
	(((t_player **)players)[0])->pos.y, (((t_player **)players)[0])->level)
      == -1)
    return (print_error("failed to allocate new graphic message"));
  while (((t_player **)players)[++i])
    {
      tmp = answer;
      if (asprintf(&answer, "%s %d", tmp, (((t_player **)players)[i])->id)
	  == -1)
	return (print_error("failed to allocate new graphic message"));
      free(tmp);
    }
  tmp = answer;
  if (asprintf(&answer, "%s", tmp) == -1)
    return (print_error("failed to allocate new graphic message"));
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}

bool	graphic_pie(t_graphic *graphic, void *pos, void *result)
{
  char	*answer;
  bool	success;

  if (asprintf(&answer, "pie %d %d %d", ((t_vector *)pos)->x,
	       ((t_vector *)pos)->y, *(int *)result) == -1)
    return (print_error("failed to allocate new graphic message"));
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}

bool	graphic_pdi(t_graphic *graphic, void *player)
{
  char	*answer;
  bool	success;

  if (asprintf(&answer, "pdi %d", ((t_player *)player)->id) == -1)
    return (print_error("failed to allocate new graphic message"));
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}
