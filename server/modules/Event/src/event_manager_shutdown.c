#include "event.h"
#include "print_log.h"
#include "server.h"

void	event_manager_shutdown(void)
{
  print_log("Shutting down event manager...");
  list_clear(&g_server.event_manager.events, true);
}
