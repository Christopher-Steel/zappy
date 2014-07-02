# include "world.h"

static const char	*res_name[] =
  {"NOURRITURE",
   "LINEMATE",
   "DERAUMERE",
   "SIBUR",
   "MENDIANE",
   "PHIRAS",
   "THYSTAME",
   NULL};

static int	string_to_res(const char *res)
{
  int		i;

  i = 0;
  while (res_name[i] != NULL)
    {
      if (strcmp(res, res_name[i]) == 0)
	return (i);
      ++i;
    }
  return (-1);
}

bool		put_down_object(t_player *player, char *res)
{
  t_world	*world;
  int		type_res;
  unsigned int	position;

  world = g_server.world;
  position = player->pos.x + (player->pos.y * world->width);
  if ((type_res = string_to_res(res)) == -1)
    return (print_perror("Conversion failed."));
  if (player->inventory[type_res] > 0)
    {
      ++world->cell[position].res[type_res];
      --player->inventory[type_res];
      return (true);
    }
  return (false);
}

bool		take_object(t_player *player, char *res)
{
  t_world	*world;
  int		type_res;
  unsigned int	position;

  world = g_server.world;
  position = player->pos.x + (player->pos.y * world->width);
  if ((type_res = string_to_res(res)) == -1)
    return (print_perror("Conversion failed."));
  if (world->cell[position].res[type_res] > 0)
    {
      --world->cell[position].res[type_res];
      ++player->inventory[type_res];
      return (true);
    }
  return (false);
}
