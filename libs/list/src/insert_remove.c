
#include "list.h"

bool		list_insert(t_list *list, int pos, void *data)
{
  t_node	*node;
  t_node	*tmp;

  if (!(node = create_node(data)))
    return (false);
  tmp = list->nodes;
  if (pos <= 1 || !tmp)
    {
      node->next = list->nodes;
      list->nodes = node;
      ++list->size;
      return (true);
    }
  else if (pos > list->size)
    pos = list->size + 1;
  while (--pos > 1)
    tmp = tmp->next;
  node->next = tmp->next;
  tmp->next = node;
  if (!node->next)
    list->last = node;
  ++list->size;
  return (true);
}

void		list_remove(t_list *list, void *data, bool free_data)
{
  t_node	*tmp;
  t_node	*to_remove;

  if (list->nodes->data == data)
    {
      to_remove = list->nodes;
      list->nodes = list->nodes->next;
      destroy_node(to_remove, free_data);
      --list->size;
      return ;
    }
  for (tmp = list->nodes; tmp->next != NULL
	 && tmp->next->data != data; tmp = tmp->next);
  to_remove = tmp->next;
  tmp->next = tmp->next->next;
  if (!tmp->next)
    list->last = tmp;
  destroy_node(to_remove, free_data);
  --list->size;
}
