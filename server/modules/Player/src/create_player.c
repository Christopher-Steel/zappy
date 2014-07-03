#include "player.h"

t_player	*create_player(t_vector pos, enum e_ori ori,
			       t_client *client)
{
  t_player	*player;

  printf("Start create Player\n");
  if ((player = malloc(sizeof(t_player))) == NULL)
    return (NULL);
  player->inventory[0] = 10;
  player->level = 1;
  player->id = g_server.info.nb_clients;
  ++g_server.info.nb_clients;
  player->pos.x = pos.x;
  player->pos.y = pos.y;
  player->client = client;
  set_orientation(player, ori);
  printf("Player Created\n");
  return (player);
}
