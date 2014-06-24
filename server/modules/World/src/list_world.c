#include <unistd.h>
#include "world.h"

void		list_world(void)
{
  int		j;
  unsigned int	i;
  t_player	*my_player;

  i = 0;
  my_player = NULL;
  printf("height = %d and width = %d\n",
	 g_server.world->height, g_server.world->width);
  while (i < g_server.world->size)
    {
      if (g_server.world->cell[i].list_player == NULL)
	printf("0");
      else
	{
	  my_player = g_server.world->cell[i].list_player->player;
	  printf("x");
	}
      ++i;
      if (i != 0 && i % g_server.world->width == 0)
	printf("\n");
    }
  printf("\n");
  show_inventory(my_player, "toot");
  take_object(my_player, "SIBUR");
  show_inventory(my_player, "toot");
  put_down_object(my_player, "SIBUR");
  show_inventory(my_player, "toot");

  for (j = 0; j < 1000; j++)
    {
      i = 0;
      printf("height = %d and width = %d\n",
	     g_server.world->height, g_server.world->width);
      while (i < g_server.world->size)
	{
	  if (g_server.world->cell[i].list_player == NULL)
	    printf("0");
	  else
	    {
	      my_player = g_server.world->cell[i].list_player->player;
	      printf("x");
	    }
	  ++i;
	  if (i != 0 && i % g_server.world->width == 0)
	    printf("\n");
	}
      move_forward(my_player, "");
      sleep(1);
    }
}
