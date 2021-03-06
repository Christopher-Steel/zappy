/*
** handshaker_create.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Network/src/handshaker
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:33:42 2014 Valentin
** Last update Sun Jul 13 19:33:49 2014 Valentin
*/

#include <stdlib.h>
#include <string.h>

#include "graphic.h"
#include "handshaker.h"
#include "print_error.h"
#include "print_log.h"
#include "team.h"
#include "print_debug.h"

static void	handshaker_destroy(t_receiver *rec)
{
  free(rec);
}

static void	handshaker_receive(t_receiver *rec, char *msg)
{
  t_client	*client;

  client = ((t_handshaker *)rec)->client;
  client->receiver->destroy(client->receiver);
  client->receiver = NULL;
  if (strcmp(msg, "GRAPHIC") == 0)
    {
      print_debug("New graphic client connected");
      client->receiver = (t_receiver *)graphic_create(client);
    }
  else if ((client->receiver = (t_receiver *)team_create_player(msg, client))
	   == NULL)
    {
      print_log("Handshake failed. Rejected client.");
      client_write_to(client, "ko");
      client_close(client);
    }
}

t_handshaker	*handshaker_create(t_client *client)
{
  t_handshaker	*new_hs;

  if ((new_hs = malloc(sizeof(*new_hs))) == NULL)
    {
      print_perror("failed to create new handshaker");
      return (NULL);
    }
  new_hs->receive = &handshaker_receive;
  new_hs->destroy = &handshaker_destroy;
  new_hs->client = client;
  client_write_to(client, "BIENVENUE");
  return (new_hs);
}
