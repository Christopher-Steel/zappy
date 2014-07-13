/*
** event.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Event/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 18:32:11 2014 Valentin
** Last update Sun Jul 13 18:32:17 2014 Valentin
*/

#include "event.h"
#include "print_error.h"

t_event		*event_create(t_event_handler *data, t_pl_func func,
			      long double timestamp, void *arg)
{
  t_event	*event;

  if ((event = malloc(sizeof(*event))) == NULL)
    {
      print_perror("failed to allocate new event");
      return (NULL);
    }
  event->data = data;
  event->func = func;
  event->timestamp = timestamp;
  event->arg = arg;
  return (event);
}
