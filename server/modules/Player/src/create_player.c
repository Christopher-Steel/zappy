#include "player.h"
#include "print_error.h"
#include "print_log.h"

static void	player_receive(t_receiver *rec, char *msg)
{
  t_player	*player;
  t_list	*inbound;

  player = (t_player *)rec;
  inbound = &player->client->inbound;
  if (list_size(inbound) < MAX_CLIENT_OUTQ)
    list_push_back(inbound, msg);
  else
    free(msg);
}

static void	player_destroy(t_receiver *rec)
{
  t_player	*player;

  player = (t_player *)rec;
  --g_server.info.nb_clients;
  remove_player(player->id, player->pos.x + player->pos.y
		* gs_get_map_width());
  free(player);
}

t_player	*create_player(t_client *client)
{
  t_player	*pl;

  if ((pl = malloc(sizeof(*pl))) == NULL)
    {
      print_error("Failed to create new player.");
      return (NULL);
    }
  pl->receive = &player_receive;
  pl->destroy = &player_destroy;
  pl->inventory[0] = 10;
  pl->level = 1;
  pl->id = g_server.info.nb_clients;
  ++g_server.info.nb_clients;
  pl->pos.x = rand() % g_server.world->height;
  pl->pos.y = rand() % g_server.world->width;
  pl->client = client;
  set_orientation(pl, rand() % 4);
  printf_log("Created new player %d at position %d/%d -> %d.", pl->id,
	     pl->pos.x, pl->pos.y, pl->orientation.orientation);
  return (pl);
}
