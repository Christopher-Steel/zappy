
#include "list.h"

bool		list_insert(t_list *list, int pos, void *data)
{
  t_node	*node;
  t_node	*tmp;

  if (!(node = create_node(data)))
    return (false);
  tmp = list->nodes;
  if (pos < 0)
    pos = 0;
  else if (pos > list->size)
    pos = list->size;
  while (--pos > 1)
    tmp = tmp->next;
  if (tmp)
    {
      node->next = tmp->next;
      tmp->next = node;
    }
  else
    list->nodes = node;
  ++list->size;
  return (true);
}

void		list_remove(t_list *list, void *data, bool free_data)
{
  t_node	*tmp;
  t_node	*to_remove;

  for (tmp = list->nodes; tmp->next != NULL
	 && tmp->next->data != data; tmp = tmp->next);
  to_remove = tmp->next;
  tmp->next = tmp->next->next;
  destroy_node(to_remove, free_data);
  --list->size;
}
