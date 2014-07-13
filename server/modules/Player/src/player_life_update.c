/*
** player_life_update.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Player/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:03:34 2014 Valentin
** Last update Sun Jul 13 23:19:31 2014 frederic tan
*/

#include "graph_PI.h"
#include "player.h"
#include "server.h"

static void	player_death(t_player *player)
{
  graph_for_each_1_arg(&graphic_pdi, player);
  respawn_resource(player->inventory);
  client_write_to(player->client, "mort");
  client_close(player->client);
}

static void	life_update_by_player(void *pl)
{
  t_player	*player;
  t_world	*world;

  player = (t_player *)pl;
  world = &g_server.world;
  player->alive -= g_server.info.dtime;
  if (player->alive <= 0)
    {
      ++world->cell[rand() % world->size].res[FOOD];
      if (player->inventory[FOOD] <= 0)
	player_death(player);
      else
	{
	  --(player->inventory[FOOD]);
	  player->alive += 126;
	}
    }
}

static void	life_update_by_team(void *team)
{
  list_for_each(((t_team *)team)->members, &life_update_by_player);
}

void	player_life_update(void)
{
  list_for_each(g_server.team_list, &life_update_by_team);
}
