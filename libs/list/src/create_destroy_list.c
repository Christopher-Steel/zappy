#include <stdio.h>

#include "list.h"

t_list		*list_create()
{
  t_list	*tmp;

  if (!(tmp = malloc(sizeof(t_list))))
    {
      perror("malloc");
      return (NULL);
    }
  tmp->size = 0;
  tmp->nodes = NULL;
  return (tmp);
}

void		list_destroy(t_list *list)
{
  t_node	*tmp;
  t_node	*node;

  node = list->nodes;
  while (node)
    {
      tmp = node->next;
      destroy_node(node);
      node = tmp;
    }
  free(list);
}
