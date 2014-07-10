#include <math.h>
#include "vector.h"
#include "player.h"

int	calc_k(double angle)
{
  int	ret;

  ret = (angle < 22.5 && angle >= 0) ? (1) :
    ((angle >= 22.5 && angle < 67.5) ? (8) :
     ((angle >= 67.5 && angle < 112.5) ? (7) :
      ((angle >= 112.5 && angle < 157.5) ? (6) : (5))));
  if (ret == 5)
    {
      ret = (angle < 0 && angle >= -22.5) ? (1) :
	((angle <= -22.5 && angle > -67.5) ? (2) :
	 ((angle <= -67.5 && angle > -112.5) ? (3) :
	  ((angle <= -112.5 && angle > -157.5) ? (4) : (5))));
    }
  return (ret);
}

double		calc_angle(t_vector pos_player,
			   t_vector pos_dest, t_player *dest)
{
  double	scal;
  double	norm;
  double	angle;
  double	sign;
  t_vector	v;
  t_vector	u;

  u.x = pos_player.x - pos_dest.x;
  u.y = pos_player.y - pos_dest.y;
  v.x = 0;
  v.y = 0;

  if (dest->ori == NORTH || dest->ori == SOUTH)
    v.y = (dest->ori == NORTH) ? 1 : -1;
  else
    v.x = (dest->ori == EAST) ? 1 : -1;
  scal = (v.x * u.x) + (v.y * u.y);
  norm = sqrt(pow(v.y, 2) + pow(v.x, 2)) *
    sqrt(pow(u.y, 2) + pow(u.x, 2));
  angle = (180.0 / M_PI) * acos(scal/norm);
  sign = ((u.x * v.y) - (u.y * v.x)) > 0 ? 1 : -1;
  return (angle * sign);
}
