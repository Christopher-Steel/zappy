/*
** event_add.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Event/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 18:32:31 2014 Valentin
** Last update Sun Jul 13 18:32:40 2014 Valentin
*/

#include "event.h"
#include "server.h"

void		event_add(t_list *events, t_event *event)
{
  bool		added;
  t_node	*node;

  added = false;
  for (node = list_begin(events); node && node->next
	 && ((t_event *)node->data)->timestamp <= event->timestamp;
       node = node->next)
    {
      if (((t_event *)node->next->data)->timestamp > event->timestamp)
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

void	gs_event_add(t_event *event)
{
  event_add(&g_server.event_manager.events, event);
}
