#define _GNU_SOURCE
#include <stdio.h>

#include "graphic.h"
#include "print_error.h"
#include "server.h"

bool	graphic_sgt(t_graphic *graphic, __attribute__ ((unused))char *cmd)
{
  char	*answer;
  bool	success;

  if (asprintf(&answer, "sgt %d", g_server.info.tick_delay) == -1)
    {
      graphic_smg_KO(graphic);
      return (print_error("failed to create graphic answer"));
    }
 success = client_write_to(graphic->client, answer);
 free(answer);
 return (success);
}

bool	graphic_sst(t_graphic *graphic, char *cmd)
{
  int	val;
  char	*answer;
  bool	success;

  answer = strtok(cmd, "\n");
  val = atoi(answer);
  if (val == 0)
    {
      graphic_sbp(graphic);
      return (printf_error("%s is an invalid value for tick_delay", answer));
    }
  g_server.info.tick_delay = val;
  if (asprintf(&answer, "sgt %d", g_server.info.tick_delay) == -1)
    {
      graphic_smg_KO(graphic);
      return (print_error("failed to create graphic answer"));
    }
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}
