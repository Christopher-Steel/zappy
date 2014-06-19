
#include "ListStruct.h"

t_node		*create_node(void *data)
{
  t_node	*node;

  if (!(node = malloc(sizeof(t_node))))
    {
      perror("malloc");
      return (NULL);
    }
  node->data = data;
  node->next = NULL;
  return (node);
}

void	destroy_node(t_node *node)
{
  free(node->data);
  free(node);
}
