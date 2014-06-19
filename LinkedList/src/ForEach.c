
#include "ListStruct.h"

void		for_each(t_list *list, void (*fcn)(void *))
{
  t_node	*tmp;

  for (tmp = list->nodes; tmp; tmp = tmp->next)
    fcn(tmp->data);
}

void		for_each_arg(t_list *list, void (*fcn)(void *, void *), void* param)
{
  t_node	*tmp;

  for (tmp = list->nodes; tmp; tmp = tmp->next)
    fcn(tmp->data, param);
}
