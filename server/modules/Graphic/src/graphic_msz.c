#define _GNU_SOURCE
#include <stdio.h>

#include "graphic.h"
#include "print_error.h"
#include "server.h"

bool	graphic_msz(t_graphic *graphic, __attribute__ ((unused))char *cmd)
{
  char	*answer;
  bool	success;

  if (asprintf(&answer, "msz %u %u\n", gs_get_map_width(),
	       gs_get_map_height()) == -1)
    return (print_perror("failed to create graphic answer"));
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}
