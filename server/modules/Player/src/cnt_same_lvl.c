#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>

#include "world.h"

int	cnt_same_lvl(t_node *node, uint lvl)
{
  t_node	*tmp;
  int		nbr_player;

  tmp = node;
  nbr_player = 0;
  while (tmp != NULL)
    {
      if (((t_player *)node->data)->level == lvl)
	++nbr_player;
      tmp = tmp->next;
    }
  return (nbr_player);
}
