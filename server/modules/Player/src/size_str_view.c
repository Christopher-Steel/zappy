#include "print_error.h"
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

static bool	player_present(int i, int *len,
			       int *tab_view)
{
  t_world	*world;

  world = g_server.world;
  if ((i == 0 && world->cell[tab_view[i]].list_player->size > 1) ||
      (i > 0 && world->cell[tab_view[i]].list_player->size > 0))
    {
      *len += strlen("joueur");
      return (true);
    }
  return (false);
}

static bool	res_present(int i, int *len, int *tab_view, bool is_player)
{
  t_world	*world;
  int		j;
  bool		is_res;

  j = 0;
  is_res = false;
  world = g_server.world;
  while (res_name[j])
    {
      if (j == 0 && is_player == true)
	++(*len);
      if (world->cell[tab_view[i]].res[j] > 0)
	{
	  if (is_res == true)
	    *len += 1;
	  is_res = true;
	  *len += strlen(res_name[j]);
	}
      ++j;
    }
  return (is_res);
}

int	size_str_view(int *tab_view)
{
  int		i;
  bool		is_player;
  bool		is_res;
  int		len;

  i = 0;
  len = 2;
  is_player = false;
  is_res = false;
  while (tab_view[i] != -1)
    {
      if (is_res || is_player)
	++len;
      is_player = player_present(i, &len, tab_view);
      is_res = res_present(i, &len, tab_view, is_player);
      ++i;
      if (tab_view[i] != -1)
	++len;
    }
  return (len);
}
