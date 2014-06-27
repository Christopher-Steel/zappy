
#include "list.h"

void	*list_front(t_list *list)
{
  if (list->size > 0)
    return (list->nodes->data);
  return (NULL);
}
