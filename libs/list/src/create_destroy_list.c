/*
** create_destroy_list.c for List in /home/mougen_v/rendus/PSU_2013_zappy/libs/list/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 18:02:49 2014 Valentin
** Last update Sun Jul 13 18:02:50 2014 Valentin
*/

#include <stdio.h>

#include "list.h"
#include "print_error.h"

t_list		*list_create()
{
  t_list	*tmp;

  if (!(tmp = malloc(sizeof(t_list))))
    print_perror("failed to allocate new list");
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
