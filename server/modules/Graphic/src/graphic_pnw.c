/*
** graphic_pnw.c for zappy in /home/launoi_a/tmp/PSU_2013_zappy/server/modules/Graphic
** 
** Made by allyriane.launois
** Login   <launoi_a@epitech.net>
** 
** Started on  Sun Jul 13 18:43:30 2014 allyriane.launois
** Last update Sun Jul 13 18:43:45 2014 allyriane.launois
*/

#define _GNU_SOURCE
#include <stdio.h>

#include "graphic.h"
#include "print_error.h"

bool	graphic_pnw(t_graphic *graphic, void *player)
{
  char	*answer;
  bool	success;

  if (asprintf(&answer, "pnw %d %d %d %d %d %s", ((t_player *)player)->id,
	       ((t_player *)player)->pos.x,
	       ((t_player *)player)->pos.y, (((t_player *)player)->ori + 1),
	       ((t_player *)player)->level, ((t_player *)player)->team->name)
      == -1)
    return (print_error("failed to allocate new graphic message"));
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}
