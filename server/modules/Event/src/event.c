
#include "print_error.h"
#include "event.h"

t_event		*event_create(t_player *player, func_ptr func, uint timestamp,
			      void *arg)
{
  t_event	*event;

  if (!(event = malloc(sizeof(t_event))))
    print_perror("malloc");
  event->player = player;
  event->func = func;
  event->timestamp = timestamp;
  event->arg = arg;
  return (event);
}

t_event		*event_destroy(t_event *event)
{
  free(event);
  return (NULL);
};
