
#include "list.h"
#include "print_error.h"

t_node		*create_node(void *data)
{
  t_node	*node;

  if (!(node = malloc(sizeof(t_node))))
    print_perror("failed to allocate new list node");
  node->data = data;
  node->next = NULL;
  return (node);
}

void	destroy_node(t_node *node, bool free_data)
{
  if (free_data == true)
    free(node->data);
  free(node);
}
