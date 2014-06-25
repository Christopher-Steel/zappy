#include "world.h"

static void	init_ressource(t_cell *cell, const unsigned int size)
{
  unsigned int	i;
  unsigned int	j;
  int		nbr_rand;

  i = 0;
  while (i < size)
    {
      j = 0;
      while (j < 7)
	{
	  nbr_rand = rand() % 100;
	  if (nbr_rand < RES_SPAWN)
	    cell[i].res[j] = rand() % NBR_SPAWN;
	  ++j;
	}
      cell[i].list_player = list_create();
      ++i;
    }
}

bool	generate_world(const unsigned int height,
		       const unsigned int width)
{
  printf("Start to generate map\n");
  if ((g_server.world = malloc(sizeof(t_world))) == NULL)
    return (false);
  g_server.world->height = height;
  g_server.world->width = width;
  g_server.world->size = height * width;
  if ((g_server.world->cell = malloc((g_server.world->size)
				     * sizeof(t_cell))) == NULL)
    return (false);
  init_ressource(g_server.world->cell, g_server.world->size);
  printf("generate map done\n");
  return (true);
}
