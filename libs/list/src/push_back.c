
#include "list.h"

#include <stdio.h>

bool		list_push_back(t_list *list, void *data)
{
  t_node	*node;

  if (!(node = create_node(data)))
    return (false);
  if (list->size == 0)
    list->nodes = node;
  else
    list->last->next = node;
  list->last = node;
  ++list->size;
  return (true);
}
