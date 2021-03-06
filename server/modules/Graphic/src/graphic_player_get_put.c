/*
** graphic_player_get_put.c for zappy in /home/launoi_a/tmp/PSU_2013_zappy/server/modules/Graphic
** 
** Made by allyriane.launois
** Login   <launoi_a@epitech.net>
** 
** Started on  Sun Jul 13 18:41:06 2014 allyriane.launois
** Last update Sun Jul 13 18:41:18 2014 allyriane.launois
*/

#define _GNU_SOURCE
#include <stdio.h>

#include "graphic.h"
#include "print_error.h"

bool	graphic_pdr(t_graphic *graphic, void *player, void *obj)
{
  char	*answer;
  bool	success;

  if (asprintf(&answer, "pdr %d %u", ((t_player *)player)->id, *(uint *)obj)
      == -1)
    return (print_error("failed to allocate new graphic message"));
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}

bool	graphic_pgt(t_graphic *graphic, void *player, void *obj)
{
  char	*answer;
  bool	success;

  if (asprintf(&answer, "pgt %d %u", ((t_player *)player)->id, *(uint *)obj)
      == -1)
    return (print_error("failed to allocate new graphic message"));
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}

