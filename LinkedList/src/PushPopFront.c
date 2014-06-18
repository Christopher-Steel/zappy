
#include "ListStruct.h"

void		push_front(t_list *list, void *data)
{
  t_node	*node;

  node = create_node(data);
  node->next = list->nodes;
  list->nodes = node;
  ++list->size;
}

void	pop_front(t_list *list)
{
  void	*tmp;

  tmp = list->nodes;
  list->nodes = list->nodes->next;
  destroy_node(tmp);
  --list->size;
}
