/*
** cnt_same_lvl.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Player/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:06:12 2014 Valentin
** Last update Sun Jul 13 19:06:18 2014 Valentin
*/

#include "world.h"

int		cnt_same_lvl(t_node *node, uint lvl)
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
