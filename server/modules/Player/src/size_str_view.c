/*
** size_str_view.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Player/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:02:32 2014 Valentin
** Last update Sun Jul 13 19:03:01 2014 Valentin
*/

#include "print_error.h"
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

static bool	player_present(int i, int *len, int *tab_view)
{
  t_world	*world;
  t_node	*node;

  world = &g_server.world;
  if (world->cell[tab_view[i]].list_player.size > 0)
    {
      node = world->cell[tab_view[i]].list_player.nodes;
      while (node != NULL)
	{
	  *len += strlen("joueur");
	  node = node->next;
	  if (node != NULL)
	    ++(*len);
	}
      return (true);
    }
  return (false);
}

static void	cnt_res(int *len, int i, int j, int *tab_view)
{
  unsigned int	u;
  t_world	*world;

  u = 0;
  world = &g_server.world;
  while (u < world->cell[tab_view[i]].res[j])
    {
      *len += strlen(res_name[j]);
      ++u;
      if (u < world->cell[tab_view[i]].res[j])
	++(*len);
    }
}

static bool	res_present(int i, int *len, int *tab_view, bool is_player)
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
	++(*len);
      if (world->cell[tab_view[i]].res[j] > 0)
	{
	  if (is_res)
	    *len += 1;
	  is_res = true;
	  cnt_res(len, i, j, tab_view);
	}
      ++j;
    }
  return (is_res);
}

int	size_str_view(int *tab_view)
{
  bool	is_player;
  bool	is_res;
  int	i;
  int	len;

  i = 0;
  len = 4;
  is_player = false;
  is_res = false;
  while (tab_view[i] != -1)
    {
      is_player = player_present(i, &len, tab_view);
      is_res = res_present(i, &len, tab_view, is_player);
      ++i;
      if (tab_view[i] != -1)
	{
	  ++len;
	  if (is_res || is_player ||
	      (i > 0 && !is_res && !is_player))
	    ++len;
	}
    }
  return (len);
}

