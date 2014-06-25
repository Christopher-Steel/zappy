#include "world.h"

bool	add_player(t_player *player, const int pos)
{
  return (list_push_front(g_server.world->cell[pos].list_player, player));
}
