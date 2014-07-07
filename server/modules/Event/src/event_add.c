
#include "event.h"

void		event_add(t_list *events, t_event *event)
{
  bool		added;
  t_node	*node;

  added = false;
  for (node = events->nodes; node && node->next
	 && ((t_event *)node->data)->timestamp <= event->timestamp;
       node = node->next)
    {
      if ( ((t_event *)node->next->data)->timestamp > event->timestamp)
	{
	  list_insert_after(events, node, event);
	  added = true;
	  break ;
	}
    }
  if (!added)
    {
      if (!node || ((t_event *)node->data)->timestamp > event->timestamp)
	list_push_front(events, event);
      else
	list_insert_after(events, node, event);
    }
}
