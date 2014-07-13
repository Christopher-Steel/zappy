/*
** spawn_food.c for zappy in /home/launoi_a/tmp/PSU_2013_zappy/server/modules/World
** 
** Made by allyriane.launois
** Login   <launoi_a@epitech.net>
** 
** Started on  Sun Jul 13 19:18:05 2014 allyriane.launois
** Last update Sun Jul 13 19:18:20 2014 allyriane.launois
*/

#include "server.h"
#include "world.h"

void		spawn_food(__attribute__ ((unused))t_player *uplayer,
			   __attribute__ ((unused))char *unused)
{
  t_world	*world;
  unsigned int	quantity;

  world = &g_server.world;
  quantity = ((world->size * 50) / 100) + 1;
  while (quantity > 0)
    {
      ++world->cell[rand() % world->size].res[FOOD];
      --quantity;
    }
}
