
#include "event.h"
#include "print_error.h"

t_event		*event_create(void *data, t_pl_func func,
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
