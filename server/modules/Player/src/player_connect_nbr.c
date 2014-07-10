#define _GNU_SOURCE
#include <stdio.h>

#include "player.h"

bool		player_connect_nbr(void *pl,
				   __attribute__ ((unused))void *unused)
{
  t_player	*player;
  char		*str;

  player = (t_player *)pl;
  if (asprintf(&str, "%u", player->team->free_slots) == -1)
    return (false);
  client_write_to(player->client, str);
  free(str);
  return (true);
}
