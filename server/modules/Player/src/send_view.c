/*
** send_view.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Player/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:14:11 2014 Valentin
** Last update Sun Jul 13 19:14:12 2014 Valentin
*/

#include "print_error.h"
#include "print_log.h"
#include "server.h"
#include "world.h"

static const char	*res_name[] =
    {
      "nourriture",
      "linemate",
      "deraumere",
      "sibur",
      "mendiane",
      "phiras",
      "thystame",
      NULL
    };

static bool	check_player_case(char *str, int i, int *tab_view)
{
  t_world	*world;
  t_node	*node;

  world = &g_server.world;
  if (world->cell[tab_view[i]].list_player.size > 0)
    {
      node = world->cell[tab_view[i]].list_player.nodes;
      while (node != NULL)
	{
	  str = strcat(str, "joueur");
	  node = node->next;
	  if (node != NULL)
	    str = strcat(str, " ");
	}
      return (true);
    }
  return (false);
}

static void	write_nbr_res(char *str, int *tab_view, int i, int j)
{
  unsigned int	u;
  t_world	*world;

  u = 0;
  world = &g_server.world;
  while (u < world->cell[tab_view[i]].res[j])
    {
      str = strcat(str, res_name[j]);
      ++u;
      if (u < world->cell[tab_view[i]].res[j])
	str = strcat(str, " ");
    }
}

static bool	check_res_case(char *str, int *tab_view,
			       int i, bool is_player)
{
  t_world	*world;
  int		j;
  bool		is_res;

  j = 0;
  is_res = false;
  world = &g_server.world;
  while (res_name[j])
    {
      if (j == 0 && is_player)
	str = strcat(str, " ");
      if (world->cell[tab_view[i]].res[j] > 0)
	{
	  if (is_res)
	    str = strcat(str, " ");
	  is_res = true;
	  write_nbr_res(str, tab_view, i, j);
	}
      ++j;
    }
  return (is_res);
}

bool		send_view(char *str, int *tab_view, t_player *player)
{
  bool		is_player;
  bool		is_res;
  int		i;

  i = 0;
  is_player = false;
  is_res = false;
  str = strcat(str, "{ ");
  while (tab_view[i] != -1)
    {
      is_player = check_player_case(str, i, tab_view);
      is_res = check_res_case(str, tab_view, i, is_player);
      ++i;
      if (tab_view[i] != -1)
	{
	  str = strcat(str, ",");
	  if (is_res || is_player ||
	      (i > 0 && !is_res && !is_player))
	    str = strcat(str, " ");
	}
    }
  str = strcat(str, " }");
  return (client_write_to(player->client, str));
}
