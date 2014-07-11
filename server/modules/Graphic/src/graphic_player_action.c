#define _GNU_SOURCE
#include <stdio.h>

#include "graphic.h"
#include "print_error.h"

bool	graphic_pex(t_graphic *graphic, t_player *player)
{
  char	*answer;
  bool	success = true;

  if (asprintf(&answer, "pex #%d\n", player->id) == -1)
    return (print_error("failed to allocate new graphic message"));
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}

bool	graphic_pbc(t_graphic *graphic, t_player *player, char *msg)
{
  char	*answer;
  bool	success = true;

  if (asprintf(&answer, "pbc #%d %s\n", player->id, msg) == -1)
    return (print_error("failed to allocate new graphic message"));
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}

bool	graphic_pic(t_graphic *graphic, t_player **players)
{
  char	*tmp;
  char	*answer;
  bool	success;
  int	i;

  i = -1;
  if (asprintf(&answer, "pic %d %d %d", (players[0])->pos.x,
	       (players[0])->pos.y, (players[0])->level) == -1)
    return (print_error("failed to allocate new graphic message"));
  while (players[++i])
    {
      tmp = answer;
      if (asprintf(&answer, "%s #%d", tmp, (players[i])->id) == -1)
	return (print_error("failed to allocate new graphic message"));
      free(tmp);
    }
  tmp = answer;
  if (asprintf(&answer, "%s\n", tmp) == -1)
    return (print_error("failed to allocate new graphic message"));
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}

bool	graphic_pie(t_graphic *graphic, t_vector *pos, int result)
{
  char	*answer;
  bool	success;

  if (asprintf(&answer, "pie %d %d %d\n", pos->x, pos->y, result) == -1)
    return (print_error("failed to allocate new graphic message"));
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}

bool	graphic_pdi(t_graphic *graphic, t_player *player)
{
  char	*answer;
  bool	success;

  if (asprintf(&answer, "pdi #%d\n", player->id) == -1)
    return (print_error("failed to allocate new graphic message"));
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}
