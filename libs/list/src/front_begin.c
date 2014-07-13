/*
** front_begin.c for List in /home/mougen_v/rendus/PSU_2013_zappy/libs/list/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 18:06:45 2014 Valentin
** Last update Sun Jul 13 18:06:46 2014 Valentin
*/

#include "list.h"

void	*list_front(t_list *list)
{
  if (list->size > 0)
    return (list->nodes->data);
  return (NULL);
}

t_node	*list_begin(t_list *list)
{
  if (list->size > 0)
    return (list->nodes);
  return (NULL);
}
