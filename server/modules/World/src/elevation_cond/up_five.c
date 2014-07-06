#include	"server.h"

bool		up_five(void)
{
  t_elevation	*elevation;

  if ((elevation = malloc(sizeof(t_elevation))) == NULL)
    return (false);
  elevation->res[FOOD] = 0;
  elevation->res[LINEMATE] = 1;
  elevation->res[DERAUMERE] = 1;
  elevation->res[SIBUR] = 2;
  elevation->res[MENDIANE] = 0;
  elevation->res[PHIRAS] = 1;
  elevation->res[THYSTAME] = 0;
  elevation->nb_player = 4;
  elevation->lvl_min = 4;
  return (list_push_back(g_server.elevation, elevation));
}
