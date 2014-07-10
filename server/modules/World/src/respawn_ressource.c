#include "world.h"

void		respawn_ressource(unsigned int *res)
{
  t_world	*world;
  unsigned int	i;
  unsigned int	quantity;

  i = 0;
  world = g_server.world;
  while (res[i])
    {
      quantity = 0;
      while (quantity < res[i])
	{
	  ++world->cell[rand() % world->size].res[i];
	  ++quantity;
	}
      ++i;
    }
}
