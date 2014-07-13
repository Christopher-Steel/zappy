/*
** player_connect_nbr.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Player/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:05:31 2014 Valentin
** Last update Sun Jul 13 19:05:32 2014 Valentin
*/

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
