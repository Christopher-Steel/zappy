
#include "ListStruct.h"

void		insert(t_list *list, int pos, void *data)
{
  t_node	*node;
  t_node	*tmp;

  node = create_node(data);
  tmp = list->nodes;
  if (pos < 0)
    pos = 0;
  else if (pos > list->size)
    pos = list->size;
  while (pos > 0)
    {
      tmp = tmp->next;
      --pos;
    }
  node->next = tmp->next;
  tmp->next = node;
  ++list->size;
}

void		remove(t_list *list, void *data)
{
  t_node	*tmp;
  t_node	*to_remove;

  for (tmp = list->nodes; tmp->next != NULL && tmp->next->data != data; tmp = tmp->next);
  to_remove = tmp->next;
  tmp->next = tmp->next->next;
  destroy_node(to_remove);
  --list->size;
}
