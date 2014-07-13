/*
** push_back.c for List in /home/mougen_v/rendus/PSU_2013_zappy/libs/list/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 18:07:31 2014 Valentin
** Last update Sun Jul 13 20:08:32 2014 Valentin
*/

#include <stdio.h>

#include "list.h"

bool		list_push_back(t_list *list, void *data)
{
  t_node	*node;

  if (!(node = create_node(data)))
    return (false);
  if (list->size == 0)
    list->nodes = node;
  else
    list->last->next = node;
  list->last = node;
  ++list->size;
  return (true);
}
