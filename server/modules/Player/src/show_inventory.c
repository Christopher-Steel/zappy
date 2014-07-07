#include <string.h>

#include "world.h"
#include "print_error.h"

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

bool	old_show_inventory(t_player *player, char *res)
{
  bool	is_succed;
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
  if ((str = inventory_to_str(size, player)) == NULL)
    return (print_perror("Error show inventory"));
  is_succed = true;
  /* is_succed = client_write_to(player->client, str); */
  free(str);
  return (is_succed);
}

bool	show_inventory(t_player *player, __attribute__ ((unused))char *unused)
{
  char	*inventory;
  bool	rc;

  asprintf(&inventory, "{"
	   "nourriture %u, "
	   "linemate %u, "
	   "deraumere %u, "
	   "sibur %u, "
	   "mendiane %u, "
	   "phiras %u, "
	   "thystame %u"
	   "}",
	   player->inventaire[0],
	   player->inventaire[1],
	   player->inventaire[2],
	   player->inventaire[3],
	   player->inventaire[4],
	   player->inventaire[5],
	   player->inventaire[6]);
  rc = write_to_client(player->client, inventory);
  free(inventory);
  return (rc);
}
