#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>

#include "graphic.h"
#include "print_error.h"
#include "server.h"

static int	get_id(char *cmd)
{
  char		*tmp;

  tmp = strtok(cmd, "#");
  tmp = strtok(NULL, "\n");
  return (atoi(tmp));
}

static t_player	*find_player(int id)
{
  t_player	*player;
  t_node	*node;

  player = NULL;
  for (node = list_begin(g_server.team_list); node && !player; node = node->next)
    if (((t_player *)(node->data))->id == id)
      player = (t_player *)(node->data);
  return (player);
}

bool		graphic_ppo(t_graphic *graphic, char *cmd)
{
  int		id;
  bool		success;
  char		*answer;
  t_player	*player;

  id = get_id(cmd);
  player = find_player(id);
  if (!player)
    return (printf_error("can't find player with id %d", id));
  if (asprintf(&answer, "ppo #%d %u %u %u\n", player->id, player->pos.x,
	       player->pos.y, player->ori) == -1)
    return (print_error("failed to allocate new graphic message"));
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}

bool		graphic_plv(t_graphic *graphic, char *cmd)
{
  int		id;
  bool		success;
  char		*answer;
  t_player	*player;

  id = get_id(cmd);
  player = find_player(id);
  if (!player)
    return (printf_error("can't find player with id %d", id));
  if (asprintf(&answer, "plv #%d %d\n", player->id, player->level) == -1)
    return (print_error("failed to allocate new graphic message"));
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}

bool		graphic_pin(t_graphic *graphic, char *cmd)
{
  int		id;
  bool		success;
  char		*answer;
  t_player	*player;
  uint		*res;

  id = get_id(cmd);
  player = find_player(id);
  if (!player)
    return (printf_error("can't find player with id %d", id));
  res = g_server.world->cell[(player->pos.x +
			      (player->pos.y * gs_get_map_width()))].res;
  if (asprintf(&answer, "pin #%d %u %u %u %u %u %u %u %u %u\n", player->id,
	       player->pos.x, player->pos.y, res[0], res[1], res[2],
	       res[3], res[4], res[5], res[6]) == -1)
    return (print_error("failed to allocate new graphic message"));
  success = client_write_to(graphic->client, answer);
  free(answer);
  return (success);
}
