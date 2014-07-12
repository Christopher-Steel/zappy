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

static int	get_k(t_broadcast *broad)
{
  int		i;
  int		j;
  int		dist_min;

  dist_min = broad->dist[0];
  for (i = 0; i < 4; ++i)
    if (broad->dist[i] < dist_min)
      {
	dist_min = broad->dist[i];
	j = i;
      }
  i = calc_k(calc_angle(broad->pos_player[j],
			broad->pos_dest[j], broad->dest));
  printf("k:%d", i);
  return (i);
}

static void	check_best_way(void *data, t_player *player, char *msg)
{
  int		i;
  t_broadcast	broad;
  t_vector	wrap_pos[] =
    {
      {0, 0},
      {0, gs_get_map_height() / 2},
      {gs_get_map_width() / 2, 0},
      {gs_get_map_width() / 2, gs_get_map_height() / 2}
    };

  broad.dest = (t_player *)data;
  if (broad.dest->pos.x == player->pos.x && broad.dest->pos.y == player->pos.y)
    print_mess(broad.dest, 0, msg);
  else
    {
      for (i = 0; i < 4; ++i)
	{
	  broad.pos_player[i] = move_pos_player(player, wrap_pos[i]);
	  broad.pos_dest[i] = move_pos_player(broad.dest, wrap_pos[i]);
	  broad.dist[i] = pow((broad.pos_dest[i].x - broad.pos_player[i].x), 2)
	    + pow((broad.pos_dest[i].y - broad.pos_player[i].y), 2);
	}
      print_mess(broad.dest, get_k(&broad), msg);
    }
}

bool	player_broadcast(void *play, void *msg)
{
  t_node	*tmp_list;
  t_node	*tmp_player;
  t_player	*player;

  player = (t_player *)play;
  for (tmp_list = g_server.team_list->nodes;
       tmp_list; tmp_list = tmp_list->next)
    for (tmp_player = ((t_team *)(tmp_list->data))->members->nodes;
	 tmp_player; tmp_player = tmp_player->next)
      if (tmp_player->data != player)
	check_best_way(tmp_player->data, player, msg);
  return (client_write_to(player->client, "ok"));
}
