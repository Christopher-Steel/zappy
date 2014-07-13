/*
** push_pop_front.c for List in /home/mougen_v/rendus/PSU_2013_zappy/libs/list/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 18:01:42 2014 Valentin
** Last update Sun Jul 13 18:01:48 2014 Valentin
*/

#include "list.h"

bool		list_push_front(t_list *list, void *data)
{
  t_node	*node;

  if (!(node = create_node(data)))
    return (false);
  node->next = list->nodes;
  list->nodes = node;
  if (list->size == 0)
    list->last = node;
  ++list->size;
  return (true);
}

void	list_pop_front(t_list *list, bool free_data)
{
  void	*tmp;

  if (list->size == 0)
    return ;
  tmp = list->nodes;
  list->nodes = list->nodes->next;
  destroy_node(tmp, free_data);
  --(list->size);
  if (list->size == 0)
    list->last = NULL;
}
