#define _GNU_SOURCE
#include <stdio.h>

#include "graphic.h"
#include "print_error.h"

bool	graphic_pnw(t_graphic *graphic, t_player *player)
{
  char	*answer;
  bool	success;

  if (asprintf(&answer, "pnw #%d %d %d %d %d %s\n", player->id, player->pos.x,
	       player->pos.y, player->ori, player->level, player->team->name)
      == -1)
    return (print_error("failed to allocate new graphic message"));
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}
