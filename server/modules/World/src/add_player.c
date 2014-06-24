#include "world.h"

bool	add_player(t_player *player, const int pos)
{
  t_list_player		*new_node;

  if ((new_node = malloc(sizeof(t_list_player))) == NULL)
    return (false);
  new_node->player = player;
  new_node->next = g_server.world->cell[pos].list_player;
  g_server.world->cell[pos].list_player = new_node;
  return (true);
}
