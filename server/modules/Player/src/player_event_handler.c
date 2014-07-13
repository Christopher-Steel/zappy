/*
** player_event_handler.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Player/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:05:17 2014 Valentin
** Last update Sun Jul 13 19:05:19 2014 Valentin
*/

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
      list_pop_front(&player->client->inbound, true);
      client_write_to(player->client, "ko");
    }
  else
    {
      list_pop_front(&player->client->inbound, true);
      gs_event_add(player->current_event);
    }
}

void		player_event_handler(t_event *event)
{
  t_player	*player;

  player = (t_player *)event->data;
  player->current_event = NULL;
  event->func(player, event->arg);
  if (player->current_event == NULL
      && list_empty(&player->client->inbound) == false)
    player_register_event(player);
}
