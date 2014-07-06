#include "world.h"

bool		start_elevation(t_player *player, char *cmd)
{
  t_list	*elev;
  t_node	*node;

  (void)cmd;
  elev = g_server.elevation;
  while (elev->nodes != NULL)
    {
      node = elev->nodes;
      if (((t_elevation *)node->data)->lvl_min == player->level)
	{
	  printf("nb_player require %d\n", ((t_elevation *)node->data)->lvl_min);
	  return (true);
	}
      elev->nodes = elev->nodes->next;
    }
  return (false);
}
