#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>

#include "AI_PI.h"
#include "world.h"
#include "print_error.h"
#include "print_log.h"

static void	player_receive(t_receiver *rec, char *msg)
{
  t_player	*player;
  //t_list	*inbound;

  player = (t_player *)rec;
  //  inbound = &player->client->inbound;
  /* if (list_size(inbound) < MAX_CLIENT_OUTQ) */
  /*   list_push_back(inbound, msg); */
  /* else */
  /*   free(msg); */
  AI_PI(player, msg);
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

static t_player	*inform_client(t_client *client, t_player *pl)
{
  char		*str;

  if (asprintf(&str, "%u", pl->team->free_slots) == -1)
    {
      print_error("failed to allocate handshake response.");
      player_destroy((t_receiver *)pl);
      return (NULL);
    }
  client_write_to(client, str);
  free(str);
  if (asprintf(&str, "%u %u", gs_get_map_width(), gs_get_map_height()) == -1)
    {
      print_error("failed to allocate handshake response.");
      player_destroy((t_receiver *)pl);
      return (NULL);
    }
  client_write_to(client, str);
  free(str);
  return (pl);
}

t_player	*create_player(t_vector pos, enum e_ori ori,
			       t_client *client, t_team *team)
{
  t_player	*pl;

  if ((pl = calloc(1, sizeof(t_player))) == NULL)
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
  pl->pos.x = pos.x;
  pl->pos.y = pos.y;
  pl->client = client;
  pl->team = team;
  pl->ori = ori;
  pl->alive = 126;
  printf_log("Created new player %d at position %d/%d -> %d.", pl->id,
	     pl->pos.x, pl->pos.y, pl->ori);
  return (inform_client(client, pl));
}
