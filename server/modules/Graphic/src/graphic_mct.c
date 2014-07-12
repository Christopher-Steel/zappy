#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "graphic.h"
#include "print_error.h"
#include "server.h"

static bool	quit_with_error(t_graphic *graphic, char *to_free)
{
  free(to_free);
  graphic_smg_KO(graphic);
  return (print_error("failed to allocate new graphic message"));
}

static	uint	get_size(char *tmp, char *answer)
{
  return (strlen(tmp) + (answer ? strlen(answer) : 0) + 1);
}

bool	graphic_mct(t_graphic *graphic, __attribute__ ((unused)) char *cmd)
{
  uint	pos;
  char	*answer;
  char	*tmp;
  bool	success;
  uint	*res;

  pos = 0;
  answer = NULL;
  while (pos < gs_get_map_size())
    {
      res = g_server.world.cell[pos].res;
      if (asprintf(&tmp, "bct %u %u %u %u %u %u %u %u %u\n",
		   (pos % gs_get_map_width()), (pos / gs_get_map_width()),
		   res[0], res[1], res[2], res[3], res[4], res[5], res[6])
	  == -1)
	return (quit_with_error(graphic, answer));
      if (!(answer = realloc(answer, sizeof(char) * get_size(tmp, answer))))
	return (quit_with_error(graphic, tmp));
      answer = strcat(answer, tmp);
      free(tmp);
      ++pos;
    }
 success = client_write_to(graphic->client, answer);
 free(answer);
 return (success);
}
