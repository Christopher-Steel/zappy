
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

  player = (t_player *)pl;
  player->alive -= g_server.info.dtime;
  if (player->alive <= 0)
    {
      printf("player id = %d\n", player->id);
      if (player->inventory[FOOD] <= 0)
	player_death(player);
      else
	{
	  --(player->inventory[FOOD]);
	  player->alive = 126;
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
