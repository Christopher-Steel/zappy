#define _GNU_SOURCE
#include <stdio.h>

#include "graphic.h"
#include "print_error.h"

bool	graphic_pfk(t_graphic *graphic, t_player *player)
{
  char	*answer;
  bool	success;

  if (asprintf(&answer, "pfk #%d\n", player->id) == -1)
    return (print_error("failed to allocate new graphic message"));
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}

bool	graphic_enw(t_graphic *graphic, t_player *player, t_egg *egg)
{
  char	*answer;
  bool	success;

  if (asprintf(&answer, "enw #%d #%d %d %d\n", egg->id, player->id,
	       egg->pos.x, egg->pos.y) == -1)
    return (print_error("failed to allocate new graphic message"));
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}

bool	graphic_eht(t_graphic *graphic, t_egg *egg)
{
  char	*answer;
  bool	success;

  if (asprintf(&answer, "eht #%d\n", egg->id) == -1)
    return (print_error("failed to allocate new graphic message"));
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}

bool	graphic_ebo(t_graphic *graphic, t_egg *egg)
{
  char	*answer;
  bool	success;

  if (asprintf(&answer, "ebo #%d\n", egg->id) == -1)
    return (print_error("failed to allocate new graphic message"));
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}

bool	graphic_edi(t_graphic *graphic, t_egg *egg)
{
  char	*answer;
  bool	success;

  if (asprintf(&answer, "edi #%d\n", egg->id) == -1)
    return (print_error("failed to allocate new graphic message"));
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}
