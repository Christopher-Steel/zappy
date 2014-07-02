
#include "event.h"
#include "server.h"

void		event_update(t_list *events)
{
  t_node	*node;
  t_event	*event;

  node = events->nodes;
  while (node)
    {
      event = (t_event *)(node->data);
      node = node->next;
      event->timestamp -= g_server.info.dtime;
      if (event->timestamp <= 0)
	{
	  event->func(event->player, event->arg);
	  list_remove(events, event, false);
	}
    }
}
