#include "AI_PI.h"
#include "event.h"
#include "player.h"

void			player_register_event(t_player *player)
{
  t_event_handler	*handler;
  char			*in_cmd;
  t_pl_func		fn;
  double		delay;

  handler = (t_event_handler *)player;
  in_cmd = list_front(&player->client->inbound);
  if ((fn = AI_PI(&in_cmd, &delay)) == NULL
      || (player->current_event = event_create(handler, fn, delay, in_cmd))
      == NULL)
    {
      client_write_to(player->client, "ko");
      list_pop_front(&player->client->inbound, true);
    }
  else
    gs_event_add(player->current_event);
}

void		player_event_handler(t_event_handler *handler)
{
  t_player	*player;

  player = (t_player *)handler;
  player->current_event = NULL;
  list_pop_front(&player->client->inbound, true);
  if (list_empty(&player->client->inbound) == false)
    player_register_event(player);
}
