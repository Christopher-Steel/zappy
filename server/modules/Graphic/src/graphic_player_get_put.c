#define _GNU_SOURCE
#include <stdio.h>

#include "graphic.h"
#include "print_error.h"

bool	graphic_pdr(t_graphic *graphic, t_player *player, uint obj)
{
  char	*answer;
  bool	success;

  if (asprintf(&answer, "pdr #%d %u\n", player->id, obj) == -1)
    return (print_error("failed to allocate new graphic message"));
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}

bool	graphic_pgt(t_graphic *graphic, t_player *player, uint obj)
{
  char	*answer;
  bool	success;

  if (asprintf(&answer, "pgt #%d %u\n", player->id, obj) == -1)
    return (print_error("failed to allocate new graphic message"));
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}

