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

static bool	check_res_case(char *str, int *tab_view,
			       int i, bool is_player)
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

bool	send_view(char *str, int *tab_view, t_player *player)
{
  bool		is_player;
  bool		is_res;
  bool		is_succed;
  int		i;

  (void)player;
  i = 0;
  is_player = false;
  is_res = false;
  str = strcat(str, "{");
  while (tab_view[i] != -1)
    {
      if (is_res || is_player)
      	str = strcat(str, " ");
      is_player = check_player_case(str, i, tab_view);
      is_res = check_res_case(str, tab_view, i, is_player);
      ++i;
      if (tab_view[i] != -1)
  	str = strcat(str, ",");
    }
  str = strcat(str, "}");
  is_succed = true;
  is_succed = client_write_to(player->client, str);
  return (is_succed);
}
