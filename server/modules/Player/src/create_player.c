#include "player.h"

t_player	*create_player(t_client *client)
{
  unsigned int	height;
  unsigned int	width;
  t_player	*player;

  printf("Start create Player\n");
  if ((player = malloc(sizeof(t_player))) == NULL)
    return (NULL);
  player->inventory[0] = 10;
  player->level = 1;
  player->id = g_server.info.nb_clients;
  ++g_server.info.nb_clients;
  height = g_server.world->height;
  width = g_server.world->width;
  player->pos.x = rand() % width;
  player->pos.y = rand() % height;
  player->client = client;
  set_orientation(player, rand() % 4);
  printf("Player Created\n");
  return (player);
}
