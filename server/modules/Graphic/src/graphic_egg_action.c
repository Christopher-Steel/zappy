#define _GNU_SOURCE
#include <stdio.h>

#include "graphic.h"
#include "print_error.h"

bool	graphic_pfk(t_graphic *graphic, void *player)
{
  char	*answer;
  bool	success;

  if (asprintf(&answer, "pfk #%d\n", ((t_player *)player)->id) == -1)
    return (print_error("failed to allocate new graphic message"));
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}

bool	graphic_enw(t_graphic *graphic, void *pl, void *egg)
{
  char	*answer;
  bool	success;

  if (asprintf(&answer, "enw #%d #%d %d %d\n", ((t_egg *)egg)->id,
						((t_player *)pl)->id,
						((t_egg *)egg)->pos.x,
						((t_egg *)egg)->pos.y) == -1)
    return (print_error("failed to allocate new graphic message"));
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}

bool	graphic_eht(t_graphic *graphic, void *egg)
{
  char	*answer;
  bool	success;

  if (asprintf(&answer, "eht #%d\n", ((t_egg *)egg)->id) == -1)
    return (print_error("failed to allocate new graphic message"));
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}

bool	graphic_ebo(t_graphic *graphic, void *egg)
{
  char	*answer;
  bool	success;

  if (asprintf(&answer, "ebo #%d\n", ((t_egg *)egg)->id) == -1)
    return (print_error("failed to allocate new graphic message"));
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}

bool	graphic_edi(t_graphic *graphic, void *egg)
{
  char	*answer;
  bool	success;

  if (asprintf(&answer, "edi #%d\n", ((t_egg *)egg)->id) == -1)
    return (print_error("failed to allocate new graphic message"));
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}
