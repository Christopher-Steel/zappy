
#include "stdlib.h"

#include "print_error.h"
#include "event.h"

bool			event_manager_init()
{
  if (!(g_server.event_manager = malloc(sizeof(t_event_manager))))
    {
      print_perror("failed to allocate new event_manager");
      return (false);
    }
  if (!(g_server.event_manager->events = list_create()))
    {
      free(g_server.event_manager);
      return (false);
    }
  return (true);
}