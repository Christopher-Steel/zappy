#include "print_error.h"
#include "world.h"

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

bool		player_voir(t_player *player,
			    __attribute__ ((unused))char *unused)
{
  char		*str;
  int		*tab_view;
  int		len;

  if ((tab_view = init_tab_view(player)) == NULL)
    return (print_perror("failed to allocate view array"));
  get_vision_point(tab_view, player);
  len = size_str_view(tab_view);
  if ((str = malloc((len + 1) * sizeof(char))) == NULL)
    return (print_perror("failed to allocate view description"));
  str = strcpy(str, "");
  send_view(str, tab_view, player);
  free(tab_view);
  free(str);
  return (true);
}
