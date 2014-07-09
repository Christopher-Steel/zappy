#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>

#include "print_error.h"
#include "world.h"

bool	player_inventaire(t_player *player,
			  __attribute__ ((unused))char *unused)
{
  char	*inventory;
  bool	rc;

  if (asprintf(&inventory, "{"
	       "nourriture %u, "
	       "linemate %u, "
	       "deraumere %u, "
	       "sibur %u, "
	       "mendiane %u, "
	       "phiras %u, "
	       "thystame %u"
	       "}",
	       player->inventory[FOOD],
	       player->inventory[LINEMATE],
	       player->inventory[DERAUMERE],
	       player->inventory[SIBUR],
	       player->inventory[MENDIANE],
	       player->inventory[PHIRAS],
	       player->inventory[THYSTAME]) == -1)
    return (print_error("failed to generate inventory description"));
  rc = client_write_to(player->client, inventory);
  free(inventory);
  return (rc);
}
