/*
** graphic_mct.c for zappy in /home/launoi_a/tmp/PSU_2013_zappy/server/modules/Graphic
** 
** Made by allyriane.launois
** Login   <launoi_a@epitech.net>
** 
** Started on  Sun Jul 13 18:39:34 2014 allyriane.launois
** Last update Sun Jul 13 18:39:51 2014 allyriane.launois
*/

#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "graphic.h"
#include "print_error.h"
#include "server.h"

bool	graphic_mct(t_graphic *graphic, __attribute__ ((unused)) char *cmd)
{
  uint	x;
  uint	y;

  x = -1;
  while (++x < gs_get_map_height())
    {
      y = -1;
      while (++y < gs_get_map_width())
	if (!graphic_bct2(graphic, &x, &y))
	  return (false);
    }
 return (false);
}
