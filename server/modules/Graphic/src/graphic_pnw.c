#define _GNU_SOURCE
#include <stdio.h>

#include "graphic.h"
#include "print_error.h"

bool	graphic_pnw(t_graphic *graphic, void *player)
{
  char	*answer;
  bool	success;

  if (asprintf(&answer, "pnw #%d %d %d %d %d %s\n", ((t_player *)player)->id,
	       ((t_player *)player)->pos.x,
	       ((t_player *)player)->pos.y, (((t_player *)player)->ori + 1),
	       ((t_player *)player)->level, ((t_player *)player)->team->name)
      == -1)
    return (print_error("failed to allocate new graphic message"));
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}
