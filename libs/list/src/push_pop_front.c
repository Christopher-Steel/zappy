
#include "list.h"

bool		list_push_front(t_list *list, void *data)
{
  t_node	*node;

  if (!(node = create_node(data)))
    return (false);
  node->next = list->nodes;
  list->nodes = node;
  ++list->size;
  return (true);
}

void	list_pop_front(t_list *list)
{
  void	*tmp;

  tmp = list->nodes;
  list->nodes = list->nodes->next;
  destroy_node(tmp);
  --list->size;
}
