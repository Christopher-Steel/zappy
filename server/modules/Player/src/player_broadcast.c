#define _GNU_SOURCE

#include <stdio.h>
#include <math.h>
#include "player.h"
#include "server.h"
#include "vector.h"
#include "print_error.h"

static t_vector	move_pos_player(t_player *player, t_vector pos)
{
  t_vector	final_pos;

  final_pos = add_vector(player->pos, pos);
  final_pos = wrap_horizontal(final_pos);
  final_pos = wrap_vertical(final_pos);
  return (final_pos);
}

static void	print_mess(t_player *dest, int k, char *msg)
{
  char		*str;

  if (!(asprintf(&str, "message %d, %s", k, msg)))
	print_error("asprintf() failed");
  client_write_to(dest->client, str);
  free (str);
}

static int	get_min_dist(int *dist)
{
  int		i;
  int		j;
  int		dist_min;

  dist_min = dist[0];
  for (i = 0; i < 4; ++i)
    if (dist[i] < dist_min)
      {
	dist_min = dist[i];
	j = i;
      }
  return (j);
}

static void	check_best_way(void *data, t_player *player, char *msg)
{
  t_vector	wrap_pos[] =
    {
      {0,0},
      {0, gs_get_map_height() / 2},
      {gs_get_map_width() / 2, 0},
      {gs_get_map_width() / 2, gs_get_map_height() / 2}
    };
  t_vector	pos_player[4];
  t_vector	pos_dest[4];
  t_player	*dest;
  int		dist[4];
  int		i;
  int		pos_min;

  dest = (t_player *)data;
  if (dest->pos.x == player->pos.x && dest->pos.y == player->pos.y)
    print_mess(dest, 0, msg);
  else
    {
      for (i = 0; i < 4; ++i)
	{
	  pos_player[i] = move_pos_player(player, wrap_pos[i]);
	  pos_dest[i] = move_pos_player(dest, wrap_pos[i]);
	  dist[i] = pow((pos_dest[i].x - pos_player[i].x), 2)
	    + pow((pos_dest[i].y - pos_player[i].y), 2);
	}
      pos_min = get_min_dist(dist);
      i = calc_k(calc_angle(pos_player[pos_min], pos_dest[pos_min], dest));
      print_mess(dest, i, msg);
    }
}

bool	player_broadcast(void *pl, void *message)
{
  t_player	*player;
  char		*msg;
  t_node	*tmp_list;
  t_node	*tmp_player;

  player = (t_player *)pl;
  msg = (char *)message;
  for (tmp_list = g_server.team_list->nodes; tmp_list; tmp_list = tmp_list->next)
    for (tmp_player = ((t_team *)(tmp_list->data))->members->nodes; tmp_player; tmp_player = tmp_player->next)
      if (tmp_player->data != player)
	check_best_way(tmp_player->data, player, msg);
  return (client_write_to(player->client, "ok"));
}
