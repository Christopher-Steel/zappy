#include <stdio.h>

#include "list.h"

t_list		*list_create()
{
  t_list	*tmp;

  if (!(tmp = malloc(sizeof(t_list))))
    print_perror("malloc");
  tmp->size = 0;
  tmp->nodes = NULL;
  tmp->last = NULL;
  return (tmp);
}

void		list_destroy(t_list *list, bool free_data)
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
  free(list);
}
