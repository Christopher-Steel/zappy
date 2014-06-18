
#include "ListStruct.h"

t_node		*create_node(void *data)
{
  t_node	*node;

  node = malloc(sizeof(t_node));
  node->data = data;
  node->next = NULL;
}

void	destroy_node(t_node *node)
{
  free(node->data);
  free(node);
}
