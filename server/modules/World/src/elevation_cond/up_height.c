#include	"server.h"

bool		up_height(void)
{
  t_elevation	*elevation;

  if ((elevation = malloc(sizeof(t_elevation))) == NULL)
    return (false);
  elevation->res[FOOD] = 0;
  elevation->res[LINEMATE] = 2;
  elevation->res[DERAUMERE] = 2;
  elevation->res[SIBUR] = 2;
  elevation->res[MENDIANE] = 2;
  elevation->res[PHIRAS] = 2;
  elevation->res[THYSTAME] = 1;
  elevation->nb_player = 6;
  elevation->lvl_min = 7;
  return (list_push_back(g_server.elevation, elevation));
}
