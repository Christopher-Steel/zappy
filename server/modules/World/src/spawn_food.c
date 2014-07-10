#include "world.h"

void		spawn_food(__attribute__ ((unused))t_player *uplayer,
			   __attribute__ ((unused))char *unused)
{
  t_world	*world;
  unsigned int	quantity;

  world = g_server.world;
  quantity = (world->size * 50) / 100;
  while (quantity > 0)
    {
      ++world->cell[rand() % world->size].res[FOOD];
      --quantity;
    }
}
