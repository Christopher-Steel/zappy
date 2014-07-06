#include	"server.h"

bool		up_four(void)
{
  t_elevation	*elevation;

  if ((elevation = malloc(sizeof(t_elevation))) == NULL)
    return (false);
  elevation->res[FOOD] = 0;
  elevation->res[LINEMATE] = 2;
  elevation->res[DERAUMERE] = 0;
  elevation->res[SIBUR] = 1;
  elevation->res[MENDIANE] = 0;
  elevation->res[PHIRAS] = 2;
  elevation->res[THYSTAME] = 0;
  elevation->nb_player = 2;
  elevation->lvl_min = 3;
  return (list_push_back(g_server.elevation, elevation));
}
