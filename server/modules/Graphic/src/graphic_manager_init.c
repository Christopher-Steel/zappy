#include "graphic.h"
#include "print_log.h"
#include "server.h"

void		graphic_manager_init(void)
{
  t_list	*list;

  print_log("Initializing graphic manager...");
  list = &g_server.graphic_manager.graphic_handlers;
  list->size = 0;
  list->nodes = NULL;
  list->last = NULL;
  print_log("Graphic manager initialized.");
}
