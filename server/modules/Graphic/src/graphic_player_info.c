#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>

#include "graphic.h"
#include "print_error.h"
#include "server.h"

static int	get_id(char *cmd)
{
  char		*tmp;

  if (cmd[0] != '#')
    return (-1);
  tmp = strtok(cmd, "#\n");
  if (tmp)
    return (atoi(tmp));
  return (-1);
}

static t_player	*find_player(int id)
{
  t_player	*player;
  t_node	*node_l;
  t_node	*node_pl;

  player = NULL;
  for (node_l = list_begin(g_server.team_list); node_l && !player;
       node_l = node_l->next)
    {
      for (node_pl = list_begin(((t_team *)node_l->data)->members);
	   node_pl && !player; node_pl = node_pl->next)
	if (((t_player *)(node_pl->data))->id == id)
	  player = (t_player *)(node_pl->data);
    }
  return (player);
}

bool		graphic_ppo(t_graphic *graphic, char *cmd)
{
  int		id;
  bool		success;
  char		*answer;
  t_player	*player;

  if ((id = get_id(cmd)) == -1)
    {
      graphic_sbp(graphic);
      return (print_error("can't get player id"));
    }
  if (!(player = find_player(id)))
    {
      graphic_sbp(graphic);
      return (printf_error("can't find player with id %d", id));
    }
  if (asprintf(&answer, "ppo #%d %u %u %u\n", player->id, player->pos.x,
	       player->pos.y, (player->ori + 1)) == -1)
    {
      graphic_smg_KO(graphic);
      return (print_error("failed to allocate new graphic message"));
    }
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

  if ((id = get_id(cmd)) == -1)
    {
      graphic_sbp(graphic);
      return (print_error("can't get player id"));
    }
  if (!(player = find_player(id)))
    {
      graphic_sbp(graphic);
      return (printf_error("can't find player with id %d", id));
    }
  if (asprintf(&answer, "plv #%d %d\n", player->id, player->level) == -1)
    {
      graphic_smg_KO(graphic);
      return (print_error("failed to allocate new graphic message"));
    }
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

  if ((id = get_id(cmd)) == -1)
    {
      graphic_sbp(graphic);
      return (print_error("can't get player id"));
    }
  if (!(player= find_player(id)))
    {
      graphic_sbp(graphic);
      return (printf_error("can't find player with id %d", id));
    }
  res = player->inventory;
  if (asprintf(&answer, "pin #%d %u %u %u %u %u %u %u %u %u\n", player->id,
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
