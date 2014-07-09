#include "print_error.h"
#include "print_log.h"
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

  world = g_server.world;
  if ((i == 0 && world->cell[tab_view[i]].list_player->size > 1) ||
      (i > 0 && world->cell[tab_view[i]].list_player->size > 0))
    {
      str = strcat(str, "joueur");
      return (true);
    }
  return (false);
}

static bool	check_egg_case(char *str, int i, int *tab_view, bool is_player)
{
  t_world	*world;

  world = g_server.world;
  if (is_player)
    str = strcat(str, " ");
  if (world->cell[tab_view[i]].list_egg->size > 0)
    {
      str = strcat(str, "oeuf");
      return (true);
    }
  return (false);
}

static bool	check_res_case(char *str, int *tab_view,
			       int i, t_in_view view)
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
	str = strcat(str, " ");
      if (world->cell[tab_view[i]].res[j] > 0)
	{
	  if (is_res == true)
	    str = strcat(str, " ");
	  is_res = true;
	  str = strcat(str, res_name[j]);
	}
      ++j;
    }
  return (is_res);
}

bool		send_view(char *str, int *tab_view, t_player *player)
{
  t_in_view	view;
  int		i;

  (void)player;
  i = 0;
  view.is_player = false;
  view.is_egg = false;
  view.is_res = false;
  str = strcat(str, "{");
  while (tab_view[i] != -1)
    {
      if (view.is_res || view.is_player || view.is_egg)
      	str = strcat(str, " ");
      view.is_player = check_player_case(str, i, tab_view);
      view.is_egg = check_egg_case(str, i, tab_view, view.is_player);
      view.is_res = check_res_case(str, tab_view, i, view);
      ++i;
      if (tab_view[i] != -1)
  	str = strcat(str, ",");
    }
  str = strcat(str, "}");
  return (client_write_to(player->client, str));
}
