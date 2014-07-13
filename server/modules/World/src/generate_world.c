#include "print_error.h"
#include "print_log.h"
#include "server.h"
#include "world.h"

static void	spawn_minimum(t_cell *cell, const unsigned int size)
{
  unsigned int	i;
  unsigned int	j;

  i = 0;
  while (i < 7)
    {
      j = 0;
      while (j < 2)
	{
	  ++cell[rand() % size].res[i];
	  ++j;
	}
      ++i;
    }
}

static void	spawn_resource(t_cell *cell, const unsigned int size)
{
  unsigned int	i;
  unsigned int	j;
  unsigned int	nbr_case;

  i = 0;
  nbr_case = ((size * RES_SPAWN) / 100) + 1;
  while (i < nbr_case)
    {
      j = 0;
      while (j < 7)
	{
	  ++cell[rand() % size].res[j];
	  ++j;
	}
      ++i;
    }
}

static void	init_ressource(t_cell *cell, const unsigned int size)
{
  spawn_minimum(cell, size);
  spawn_resource(cell, size);
}

bool	generate_world(const unsigned int height,
		       const unsigned int width)
{
  print_log("Generating world...");
  g_server.world.height = height;
  g_server.world.width = width;
  g_server.world.size = height * width;
  if ((g_server.world.cell =
       calloc(g_server.world.size, sizeof(t_cell))) == NULL)
    return (print_error("World generation failed."));
  init_ressource(g_server.world.cell, g_server.world.size);
  print_log("World generated.");
  return (true);
}
