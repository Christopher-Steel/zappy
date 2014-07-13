/*
** for_each.c for List in /home/mougen_v/rendus/PSU_2013_zappy/libs/list/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 18:02:24 2014 Valentin
** Last update Sun Jul 13 18:02:26 2014 Valentin
*/

#include "list.h"

void		list_for_each(t_list *list, void (*fcn)(void *))
{
  t_node	*tmp;

  for (tmp = list->nodes; tmp; tmp = tmp->next)
    fcn(tmp->data);
}

void		list_for_each_arg(t_list *list, void (*fcn)(void *, void *),
				  void *arg)
{
  t_node	*tmp;

  for (tmp = list->nodes; tmp; tmp = tmp->next)
    fcn(tmp->data, arg);
}
