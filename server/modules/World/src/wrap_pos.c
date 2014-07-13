/*
** wrap_pos.c for zappy in /home/launoi_a/tmp/PSU_2013_zappy/server/modules/World
** 
** Made by allyriane.launois
** Login   <launoi_a@epitech.net>
** 
** Started on  Sun Jul 13 19:19:29 2014 allyriane.launois
** Last update Sun Jul 13 19:19:35 2014 allyriane.launois
*/

#include "server.h"
#include "world.h"

t_vector	wrap_vertical(t_vector vec)
{
  t_vector	pos;
  int		height;

  height = gs_get_map_height();
  pos = vec;
  if (vec.y < 0)
    pos.y = height + vec.y;
  else if (vec.y >= height)
    pos.y = vec.y - height;
  return (pos);
}

t_vector	wrap_horizontal(t_vector vec)
{
  t_vector	pos;
  int		width;

  width = gs_get_map_width();
  pos = vec;
  if (vec.x < 0)
    pos.x = width + vec.x;
  else if (vec.x >= width)
    pos.x = vec.x - width;
  return (pos);
}
