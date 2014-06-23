#include "world.h"

void		spawn_ressource(t_world *world)
{
  unsigned int	i;
  int		nbr_rand;

  i = 0;
  while (i < world->size)
    {
      nbr_rand = rand();
      if (nbr_rand < RES_SPAWN)
	world->cell[i].res[0] = rand() % NBR_SPAWN;
      ++i;
    }
}
