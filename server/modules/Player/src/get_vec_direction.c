#include "player.h"

t_vector	get_vec_direction(enum e_ori ori)
{
  t_vector	tab[] =
    {
      {0, -1},
      {1, 0},
      {0, 1},
      {-1, 0}
    };

  return (tab[ori]);
}
