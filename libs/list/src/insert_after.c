
#include "list.h"

bool		list_insert_after(t_list *list, t_node *prev_node, void *data)
{
  t_node	*node;

  if (!(node = create_node(data)))
    return (false);
  node->next = prev_node->next;
  if (!node->next)
    list->last = node;
  prev_node->next = node;
  ++(list->size);
  return (true);
}
