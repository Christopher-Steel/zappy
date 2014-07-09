#include "player.h"

bool	player_broadcast(t_player *player, char *msg)
{
  (void)player;
  (void)msg;
  client_write_to(player->client, "ok");
  return (true);
}
