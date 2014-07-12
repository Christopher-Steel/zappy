#define _GNU_SOURCE
#include <stdio.h>

#include "graphic.h"
#include "print_error.h"

bool	graphic_seg(t_graphic *graphic, void *team_name)
{
  char	*answer;
  bool	success;

  if (asprintf(&answer, "seg %s", (char *)team_name) == -1)
    return (print_error("failed to allocate new graphic message"));
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}

bool	graphic_smg(t_graphic *graphic, void *msg)
{
  char	*answer;
  bool	success;

  if (asprintf(&answer, "smg %s", (char *)msg) == -1)
    return (print_error("failed to allocate new graphic message"));
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}

bool	graphic_smg_KO(t_graphic *graphic)
{
  return (client_write_to(graphic->client, "smg KO"));
}
