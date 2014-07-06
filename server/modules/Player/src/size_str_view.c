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

static bool	egg_present(int i, int *len, int *tab_view, bool is_player)
{
  t_world	*world;

  world = g_server.world;
  if (is_player == true)
    ++(*len);
  if (world->cell[tab_view[i]].list_egg->size > 0)
    {
      *len += strlen("oeuf");
      return (true);
    }
  return (false);
}

static bool	res_present(int i, int *len, int *tab_view, t_in_view view)
{
  t_world	*world;
  int		j;
  bool		is_res;

  j = 0;
  is_res = false;
  world = g_server.world;
  while (res_name[j])
    {
      if (j == 0 && (view.is_player || view.is_egg))
	++(*len);
      if (world->cell[tab_view[i]].res[j] > 0)
	{
	  if (is_res)
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
  t_in_view	view;
  int		len;

  i = 0;
  len = 2;
  view.is_player = false;
  view.is_res = false;
  view.is_egg = false;
  while (tab_view[i] != -1)
    {
      if (view.is_res || view.is_player || view.is_egg)
	++len;
      view.is_player = player_present(i, &len, tab_view);
      view.is_egg = egg_present(i, &len, tab_view, view.is_player);
      view.is_res = res_present(i, &len, tab_view, view);
      ++i;
      if (tab_view[i] != -1)
	++len;
    }
  return (len);
}

