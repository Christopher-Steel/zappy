#include "print_error.h"
#include "server.h"
#include "world.h"

static const char	*res_name[] =
  {
    "NOURRITURE",
    "LINEMATE",
    "DERAUMERE",
    "SIBUR",
    "MENDIANE",
    "PHIRAS",
    "THYSTAME",
    NULL
  };

static int	string_to_res(char *res)
{
  int		i;

  i = 0;
  while (res_name[i] != NULL)
    {
      if (strcasecmp(res, res_name[i]) == 0)
	return (i);
      ++i;
    }
  return (-1);
}

bool		player_pose(void *pl, void *resource)
{
  t_player	*player;
  char		*res;
  t_world	*world;
  int		type_res;
  unsigned int	position;

  player = (t_player *)pl;
  res = (char *)resource;
  world = &g_server.world;
  position = player->pos.x + (player->pos.y * world->width);
  if ((type_res = string_to_res(res)) == -1)
    {
      client_write_to(player->client, "ko");
      return (printf_error("Unknown resource: [%s[%zu]]", res, strlen(res)));
    }
  if (player->inventory[type_res] > 0)
    {
      ++world->cell[position].res[type_res];
      --player->inventory[type_res];
      return (client_write_to(player->client, "ok"));
    }
  return (client_write_to(player->client, "ko"));
}

bool		player_prend(void *pl, void *resource)
{
  t_player	*player;
  char		*res;
  t_world	*world;
  int		type_res;
  unsigned int	position;

  player = (t_player *)pl;
  res = (char *)resource;
  world = &g_server.world;
  position = player->pos.x + (player->pos.y * world->width);
  if ((type_res = string_to_res(res)) == -1)
    {
      client_write_to(player->client, "ko");
      return (printf_error("Unknown resource: [%s[%zu]]", res, strlen(res)));
    }
  if (world->cell[position].res[type_res] > 0)
    {
      --world->cell[position].res[type_res];
      ++player->inventory[type_res];
      return (client_write_to(player->client, "ok"));
    }
  return (client_write_to(player->client, "ko"));
}
