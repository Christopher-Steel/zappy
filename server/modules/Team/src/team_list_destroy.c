#include "print_log.h"
#include "server.h"
#include "team.h"

static void	team_list_node_destroy(void *node)
{
  team_destroy(node);
}

void	team_list_destroy(void)
{
  print_log("Deleting teams...");
  list_for_each(g_server.team_list, &team_list_node_destroy);
  list_clear(g_server.team_list, false);
  free(g_server.team_list);
}
