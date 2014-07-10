
#include "event.h"
#include "server.h"

static void	event_node_update(void *data, void *list)
{
  t_event	*event;
  t_player	*player;

  event = (t_event *)data;
  player = (t_player *)event->data;
  event->timestamp -= g_server.info.dtime;
  if (event->timestamp <= 0)
    {
      event->func(player, event->arg);
      player->current_event = NULL;
      list_pop_front(&player->client->inbound, true);
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
