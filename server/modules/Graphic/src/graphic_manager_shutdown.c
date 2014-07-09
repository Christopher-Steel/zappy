#include "graphic.h"
#include "print_log.h"
#include "server.h"

void	graphic_manager_shutdown(void)
{
  print_log("Shutting down graphic manager...");
  list_clear(&g_server.graphic_manager.graphic_handlers, true);
}
