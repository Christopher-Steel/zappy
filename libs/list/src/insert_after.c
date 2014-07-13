/*
** insert_after.c for List in /home/mougen_v/rendus/PSU_2013_zappy/libs/list/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 18:02:11 2014 Valentin
** Last update Sun Jul 13 18:02:12 2014 Valentin
*/

#include "list.h"

bool		list_insert_after(t_list *list, t_node *prev_node, void *data)
{
  t_node	*node;

  if (!(node = create_node(data)))
    return (false);
  node->next = prev_node->next;
  if (!node->next)
    list->last = node;
  prev_node->next = node;
  ++(list->size);
  return (true);
}
