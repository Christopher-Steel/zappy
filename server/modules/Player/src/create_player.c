#include "player.h"

t_player	*create_player(const t_vector pos, const enum e_ori ori,
			       const t_sock socket)
{
  t_player	*player;

  printf("Start create Player\n");
  if ((player = malloc(sizeof(t_player))) == NULL)
    return (NULL);
  player->inventory[0] = 10;
  player->level = 1;
  player->socket = socket;
  player->id = g_server.info.nb_clients;
  ++g_server.info.nb_clients;
  player->pos.x = pos.x;
  player->pos.y = pos.y;
  set_orientation(player, ori);
  printf("Player Created\n");
  return (player);
}
