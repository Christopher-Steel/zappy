#include "event.h"
#include "print_log.h"
#include "server.h"

void	event_manager_init(void)
{
  t_list	*list;

  print_log("Initializing event manager...");
  list = &g_server.event_manager.events;
  list->size = 0;
  list->nodes = NULL;
  list->last = NULL;
  print_log("Event manager initialized.");
}
