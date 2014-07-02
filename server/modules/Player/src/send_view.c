#include "world.h"

static const char	*res_name[] =
    {
      "nourritue",
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
      strcat(str, "joueur");
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
	strcat(str, " ");
      if (world->cell[tab_view[i]].res[j] > 0)
	{
	  if (is_res == true)
	    strcat(str, " ");
	  is_res = true;
	  strcat(str, res_name[j]);
	}
      ++j;
    }
  return (is_res);
}

bool	send_view(int len, int *tab_view)
{
  bool		is_player;
  bool		is_res;
  char		*str;
  int		i;

  i = 0;
  is_player = false;
  is_res = false;
  if ((str = malloc(len * sizeof(char))) == NULL)
    return (print_perror("Malloc error\n"));
  while (tab_view[i] != -1)
    {
      if (is_res || is_player)
      	strcat(str, " ");
      is_player = check_player_case(str, i, tab_view);
      is_res = check_res_case(str, tab_view, i, is_player);
      ++i;
      if (tab_view[i] != -1)
	strcat(str, ",");
    }
  printf("%s\n", str);
  return (true);
}
