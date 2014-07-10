
#include "event.h"
#include "server.h"

static void	event_node_update(void *data, void *list)
{
  t_event	*event;

  event = (t_event *)data;
  event->timestamp -= g_server.info.dtime;
  if (event->timestamp <= 0)
    {
      event->func(event->player, event->arg);
      event->player->current_event = NULL;
      list_pop_front(&event->player->client->inbound, true);
      list_pop_front((t_list *)list, true);
    }
}

void		event_update(t_list *events)
{
  list_for_each_arg(events, &event_node_update, events);
}
