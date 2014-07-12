#include "egg.h"
#include "event.h"

void	egg_event_handler(t_event *event)
{
  event->func(event->data, event->arg);
}
