
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
