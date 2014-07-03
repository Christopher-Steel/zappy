#include "world.h"

bool	add_egg(t_egg *egg, const int pos)
{
  return (list_push_front(g_server.world->cell[pos].list_egg, egg));
}
