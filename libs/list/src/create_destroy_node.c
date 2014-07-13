/*
** create_destroy_node.c for List in /home/mougen_v/rendus/PSU_2013_zappy/libs/list/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 18:06:04 2014 Valentin
** Last update Sun Jul 13 18:06:05 2014 Valentin
*/

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
