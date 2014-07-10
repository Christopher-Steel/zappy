#include "world.h"

void		respawn_ressource(unsigned int *res)
{
  t_world	*world;
  unsigned int	quantity;

  i = 0;
  world = g_server.world;
  quantity = (world->size * 50) / 100;
  while (quantity > 0)
    {
      ++world->cell[rand() % world->size].res[i];
      --quantity;
    }
}
