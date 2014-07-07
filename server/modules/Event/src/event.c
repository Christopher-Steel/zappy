
#include "event.h"
#include "print_error.h"

t_event		*event_create(t_player *player, func_ptr func,
			      long double timestamp, void *arg)
{
  t_event	*event;

  if (!(event = malloc(sizeof(t_event))))
    {
      print_perror("failed to allocate new event");
      return (NULL);
    }
  event->player = player;
  event->func = func;
  event->timestamp = timestamp;
  event->arg = arg;
  return (event);
}
