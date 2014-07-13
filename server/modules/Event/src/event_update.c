/*
** event_update.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Event/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 18:31:35 2014 Valentin
** Last update Sun Jul 13 18:31:36 2014 Valentin
*/

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
      free(event->arg);
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
