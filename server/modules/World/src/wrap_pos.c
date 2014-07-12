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
