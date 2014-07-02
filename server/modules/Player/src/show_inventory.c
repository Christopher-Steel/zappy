#include <string.h>

#include "world.h"

static const char	*elem_inven[] =
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

static char	*inventory_to_str(int size, t_player *player)
{
  int		i;
  char		*str;

  if ((str = malloc(size * sizeof(char))) == NULL)
    return (NULL);
  i = 1;
  while (elem_inven[i])
    {
      strcat(str, elem_inven[i]);
      strcat(str, " ");
      strcat(str, convert_nbr_to_str(player->inventory[i++]));
      strcat(str, ", ");
    }
  strcat(str, elem_inven[0]);
  strcat(str, " ");
  strcat(str, convert_nbr_to_str(player->inventory[0]));
  return (str);
}

bool	show_inventory(t_player *player, char *res)
{
  int	i;
  int	size;
  char	*str;

  (void)res;
  i = 0;
  size = 0;
  while (elem_inven[i])
    {
      size += strlen(elem_inven[i]);
      if ((str = convert_nbr_to_str(player->inventory[i])) == NULL)
	return (false);
      size += strlen(str);
      size += 3;
      free(str);
      ++i;
    }
  inventory_to_str(size, player);
  return (true);
}
