
#include "event.h"
#include "server.h"

void		update(void *data, void *list)
{
  t_event	*event;

  event = (t_event *)data;
  event->timestamp -= g_server.info.dtime;
  if (event->timestamp <= 0)
    {
      event->func(event->player, event->arg);
      list_pop_front((t_list *)list, false);
    }
}

void		event_update(t_list *events)
{
  list_for_each_arg(events, &update, events);
}
