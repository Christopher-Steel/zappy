#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>

#include "graphic.h"
#include "print_error.h"
#include "server.h"

static bool	get_position(char *cmd, uint *x, uint *y)
{
  char		*tmp;

  tmp = strtok(cmd, " \n");
  if (tmp)
    *x = atoi(tmp);
  else
    return (false);

  tmp = strtok(NULL, " \n");
  if (tmp)
    *y = atoi(tmp);
  else
    return (false);
  return (true);
}

bool	graphic_bct(t_graphic *graphic, char *cmd)
{
  uint	x;
  uint	y;
  bool	success;
  char	*answer;
  uint	*res;

  if (!get_position(cmd, &x, &y))
    return (printf_error("\"%s\" is a bad case position", strtok(cmd, "\n")));
  if (x < gs_get_map_width() && gs_get_map_height())
    return (print_error("invalid map position"));
  res = g_server.world->cell[(x + (y * gs_get_map_width()))].res;
  if (asprintf(&answer, "bct %u %u %u %u %u %u %u %u %u\n", x, y, res[0],
	       res[1], res[2], res[3], res[4], res[5], res[6]) == -1)
    return (print_perror("faile to allocate new graphic message"));
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}
