/*
** graphic_msz.c for zappy in /home/launoi_a/tmp/PSU_2013_zappy/server/modules/Graphic
** 
** Made by allyriane.launois
** Login   <launoi_a@epitech.net>
** 
** Started on  Sun Jul 13 18:40:15 2014 allyriane.launois
** Last update Sun Jul 13 18:40:17 2014 allyriane.launois
*/

#define _GNU_SOURCE
#include <stdio.h>

#include "graphic.h"
#include "print_error.h"
#include "server.h"

bool	graphic_msz(t_graphic *graphic, __attribute__ ((unused))char *cmd)
{
  char	*answer;
  bool	success;

  if (asprintf(&answer, "msz %u %u", gs_get_map_width(),
	       gs_get_map_height()) == -1)
    return (print_perror("failed to create graphic answer"));
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}
