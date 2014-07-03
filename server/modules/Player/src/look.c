#include "print_error.h"
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

static int	*init_tab_view(t_player *player)
{
  unsigned int	i;
  int		*tab;
  int		tmp;
  int		nbr_case;

  nbr_case = 1;
  tmp = 1;
  i = 0;
  while (i < player->level)
    {
      tmp = tmp + 2;
      nbr_case = nbr_case + tmp;
      ++i;
    }
  if ((tab = malloc((nbr_case) * sizeof(int))) == NULL)
    return (NULL);
  tab[nbr_case] = -1;
  return (tab);
}

static int	size_str(int *tab_view, t_world *world)
{
  int		i;
  int		j;
  int		len;

  i = 0;
  len = 0;
  while (tab_view[i] != -1)
    {
      j = 0;
      if ((i == 0 && world->cell[tab_view[i]].list_player->size > 1) ||
	  (i > 0 && world->cell[tab_view[i]].list_player->size > 0))
	len += strlen("joueur") + 1;
      while (res_name[j])
      	{
      	  if (world->cell[tab_view[i]].res[j] > 0)
	    len += strlen(res_name[j]) + 1;
      	  ++j;
      	}
      ++i;
      ++len;
    }
  return (len);
}

bool		look(t_player *player, char *cmd)
{
  t_world	*world;
  int		*tab_view;
  int		len;

  (void)cmd;
  world = g_server.world;
  if ((tab_view = init_tab_view(player)) == NULL)
    return (print_perror("Malloc error\n"));
  get_vision_point(tab_view, player);
  len = size_str(tab_view, world);
  send_view(len, tab_view);
  free(tab_view);
  return (true);
}
