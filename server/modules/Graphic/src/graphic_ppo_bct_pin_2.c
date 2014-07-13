#define	_GNU_SOURCE

#include <stdio.h>

#include "graph_PI.h"
#include "print_error.h"
#include "server.h"

bool	graphic_ppo2(t_graphic *graphic, void *player)
{
  char	*info;

  if (asprintf(&info, "ppo #%d %u %u %u", ((t_player *)player)->id,
	       ((t_player *)player)->pos.x, ((t_player *)player)->pos.y,
	       (((t_player *)player)->ori + 1)) == -1)
    return (print_error("failed to allocate new graphic message"));
  client_write_to(graphic->client, info);
  free(info);
  return (true);
}

bool	graphic_bct2(t_graphic *graphic, void *arg1, void *arg2)
{
  char	*answer;
  bool	success;
  uint	x;
  uint	y;
  uint	*res;

  x = *((uint *)arg1);
  y = *((uint *)arg2);
  res = g_server.world.cell[(x + (y * gs_get_map_width()))].res;
  if (asprintf(&answer, "bct %u %u %u %u %u %u %u %u %u", x, y, res[0],
	       res[1], res[2], res[3], res[4], res[5], res[6]) == -1)
    {
      graphic_smg_KO(graphic);
      return (print_perror("fail to allocate new graphic message"));
    }
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}

bool		graphic_pin2(t_graphic *graphic, void *pl)
{
  t_player	*player;
  char		*answer;
  bool		success;
  uint		*res;

  player = (t_player *)pl;
  res = player->inventory;
  if (asprintf(&answer, "pin #%d %u %u %u %u %u %u %u %u %u", player->id,
	       player->pos.x, player->pos.y, res[0], res[1], res[2],
	       res[3], res[4], res[5], res[6]) == -1)
    {
      graphic_smg_KO(graphic);
      return (print_error("failed to allocate new graphic message"));
    }
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}

bool		graphic_plv2(t_graphic *graphic, void *pl)
{
  bool		success;
  t_player	*player;
  char		*answer;

  player = (t_player *)pl;
  if (asprintf(&answer, "plv #%d %d", player->id, player->level) == -1)
    return (print_error("failed to allocate new graphic message"));
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}
