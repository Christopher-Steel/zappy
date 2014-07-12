
#include "event.h"
#include "server.h"

static bool	event_node_update(void *data)
{
  t_event	*event;

  event = (t_event *)data;
  event->timestamp -= g_server.info.dtime;
  if (event->timestamp <= 0)
    {
      event->data->event_handler(event);
      return (true);
    }
  else
    return (false);
}

void	event_update(t_list *events)
{
  list_filter(events, &event_node_update);
}

void	gs_event_update(void)
{
  event_update(&g_server.event_manager.events);
}
