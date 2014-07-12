
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
