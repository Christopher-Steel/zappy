/*
** player_inventaire.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Player/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:13:37 2014 Valentin
** Last update Sun Jul 13 19:13:38 2014 Valentin
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>

#include "print_error.h"
#include "world.h"

bool		player_inventaire(void *pl,
				  __attribute__ ((unused))void *unused)
{
  t_player	*player;
  char		*inventory;
  bool		rc;

  player = (t_player *)pl;
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
