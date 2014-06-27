
#include "event.h"

void		event_add(t_list *events, t_event *event)
{
  int		i;
  t_node	*node;

  i = 1;
  node = events->nodes;
  while (node && ((t_event *)(node->data))->timestamp <= event->timestamp)
    {
      node = node->next;
      ++i;
    }
  list_insert(events, i, event);
}
