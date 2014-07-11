
#include "event.h"
#include "server.h"

static void	event_node_update(void *data, void *list)
{
  t_event	*event;

  event = (t_event *)data;
  event->timestamp -= g_server.info.dtime;
  if (event->timestamp <= 0)
    {
      event->func(event->data, event->arg);
      event->data->event_handler(event->data);
      list_pop_front((t_list *)list, true);
    }
}

void	event_update(t_list *events)
{
  list_for_each_arg(events, &event_node_update, events);
}

void	gs_event_update(void)
{
  event_update(&g_server.event_manager.events);
}
