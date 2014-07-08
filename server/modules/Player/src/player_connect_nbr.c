#define _GNU_SOURCE
#include <stdio.h>
#include "player.h"

bool	player_connect_nbr(t_player *player,
			   __attribute__ ((unused))char *unused)
{
  char	*str;

  asprintf(&str, "%u", player->team->free_slots);
  client_write_to(player->client, str);
  free(str);
  return (true);
}
