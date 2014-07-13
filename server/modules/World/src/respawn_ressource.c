#include "server.h"
#include "graph_PI.h"
#include "world.h"

void		respawn_resource(unsigned int *res)
{
  void		**tab;
  t_world	*world;
  unsigned int	x;
  unsigned int	y;
  unsigned int	i;
  unsigned int	quantity;

  i = 0;
  world = &g_server.world;
  while (res[i])
    {
      quantity = 0;
      while (quantity < res[i])
	{
	  x = rand() % gs_get_map_width();
	  y = rand() % gs_get_map_height();
	  tab = mount_args(&x, &y);
	  graph_for_each_2_args(&graphic_bct2, tab);
	  ++world->cell[y + (x * gs_get_map_width())].res[i];
	  ++quantity;
	}
      ++i;
    }
}
