/*
** graphic_egg_action.c for zappy in /home/launoi_a/tmp/PSU_2013_zappy/server/modules/Graphic
** 
** Made by allyriane.launois
** Login   <launoi_a@epitech.net>
** 
** Started on  Sun Jul 13 18:37:37 2014 allyriane.launois
** Last update Sun Jul 13 18:38:35 2014 allyriane.launois
*/

#define _GNU_SOURCE
#include <stdio.h>

#include "graphic.h"
#include "print_error.h"

bool	graphic_pfk(t_graphic *graphic, void *player)
{
  char	*answer;
  bool	success;

  if (asprintf(&answer, "pfk %d", ((t_player *)player)->id) == -1)
    return (print_error("failed to allocate new graphic message"));
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}

bool	graphic_enw(t_graphic *graphic, void *pl, void *egg)
{
  char	*answer;
  bool	success;

  if (asprintf(&answer, "enw %d %d %d %d", ((t_egg *)egg)->id,
	       ((t_player *)pl)->id,
	       ((t_egg *)egg)->pos.x,
	       ((t_egg *)egg)->pos.y) == -1)
    return (print_error("failed to allocate new graphic message"));
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}

bool	graphic_eht(t_graphic *graphic, void *egg)
{
  char	*answer;
  bool	success;

  if (asprintf(&answer, "eht %d", ((t_egg *)egg)->id) == -1)
    return (print_error("failed to allocate new graphic message"));
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}

bool	graphic_ebo(t_graphic *graphic, void *egg)
{
  char	*answer;
  bool	success;

  if (asprintf(&answer, "ebo %d", ((t_egg *)egg)->id) == -1)
    return (print_error("failed to allocate new graphic message"));
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}

bool	graphic_edi(t_graphic *graphic, void *egg)
{
  char	*answer;
  bool	success;

  if (asprintf(&answer, "edi %d", ((t_egg *)egg)->id) == -1)
    return (print_error("failed to allocate new graphic message"));
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}
