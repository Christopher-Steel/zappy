
#include "list.h"

#include <stdio.h>

t_node		*end_list(t_list *list)
{
  t_node	*node;

  node = list->nodes;
  while (node && node->next)
    node = node->next;
  return (node);
}

bool		list_push_back(t_list *list, void *data)
{
  t_node	*node;

  if (!(node = create_node(data)))
    return (false);
  if (list->size == 0)
    list->nodes = node;
  else
    end_list(list)->next = node;
  ++list->size;
  return (true);
}
