
#include "team.h"

bool		team_create_player(t_team *team, t_client *client)
{
  t_player	*player;

  player = create_player(client);
  if (!player)
    return (false);
  list_push_front(team->members, player);
  player->team = team;
}
