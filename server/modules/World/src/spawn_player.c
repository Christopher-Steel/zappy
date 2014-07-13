/*
** spawn_player.c for zappy in /home/launoi_a/tmp/PSU_2013_zappy/server/modules/World
** 
** Made by allyriane.launois
** Login   <launoi_a@epitech.net>
** 
** Started on  Sun Jul 13 19:18:26 2014 allyriane.launois
** Last update Sun Jul 13 19:18:34 2014 allyriane.launois
*/

#include	"world.h"
#include	"server.h"
#include	"print_log.h"
#include	"print_error.h"

static bool	add_list_player(t_player *player, unsigned int pos)
{
  bool		is_succed;

  is_succed = list_push_front(&g_server.world.cell[pos].list_player, player);
  if (!is_succed)
    {
      print_error("Cannot spawn player");
      free(player);
    }
  return (is_succed);
}

t_player	*spawn_pos_player(t_client *client, t_team *team, t_egg *egg)
{
  unsigned int	position;
  enum e_ori	ori;
  t_player	*player;

  print_log("spawn from egg");
  position = egg->pos.x + (gs_get_map_width() * egg->pos.y);
  ori = rand() % 4;
  if ((player = create_player(egg->pos, ori, client, team)) == NULL ||
      (add_list_player(player, position) == false))
      return (NULL);
  return (player);
}

t_player	*spawn_player(t_client *client, t_team *team)
{
  unsigned int	height;
  unsigned int	width;
  unsigned int	position;
  enum e_ori	ori;
  t_vector	pos;
  t_player	*player;

  print_log("spawn from connection");
  height = gs_get_map_height();
  width = gs_get_map_width();
  pos.x = rand() % width;
  pos.y = rand() % height;
  position = pos.x + (width * pos.y);
  ori = rand() % 4;
  if ((player = create_player(pos, ori, client, team)) == NULL ||
      (add_list_player(player, position) == false))
      return (NULL);
  return (player);
}
