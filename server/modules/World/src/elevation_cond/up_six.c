#include	"server.h"

bool		up_six(void)
{
  t_elevation	*elevation;

  if ((elevation = malloc(sizeof(t_elevation))) == NULL)
    return (false);
  elevation->res[FOOD] = 0;
  elevation->res[LINEMATE] = 1;
  elevation->res[DERAUMERE] = 2;
  elevation->res[SIBUR] = 1;
  elevation->res[MENDIANE] = 3;
  elevation->res[PHIRAS] = 0;
  elevation->res[THYSTAME] = 0;
  elevation->nb_player = 4;
  elevation->lvl_min = 5;
  return (list_push_back(g_server.elevation, elevation));
}
