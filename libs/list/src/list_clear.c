/*
** list_clear.c for List in /home/mougen_v/rendus/PSU_2013_zappy/libs/list/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 18:01:59 2014 Valentin
** Last update Sun Jul 13 18:02:00 2014 Valentin
*/

#include "list.h"

void		list_clear(t_list *list, bool free_data)
{
  t_node	*tmp;
  t_node	*node;

  node = list->nodes;
  while (node)
    {
      tmp = node->next;
      destroy_node(node, free_data);
      node = tmp;
    }
  list->last = NULL;
  list->size = 0;
  list->nodes = NULL;
}
