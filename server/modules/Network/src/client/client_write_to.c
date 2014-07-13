/*
** client_write_to.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Network/src/client
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:32:38 2014 Valentin
** Last update Sun Jul 13 19:32:39 2014 Valentin
*/

#include <string.h>

#include "inject_buffer.h"
#include "network_client.h"
#include "print_error.h"
#include "print_log.h"
#include "print_warning.h"

bool		client_write_to(t_client *client, char *message)
{
  t_injectbuf	*injector;
  char		*data;
  uint		len;

  if (client->closing)
    {
      print_warning("attempted to write to closing client");
      return (false);
    }
  len = strlen(message) + 2;
  printf_log("Sending message to client %s:%d [%d]: \"%s\"",
	     client->ip, client->port, client->socket, message);
  if ((data = malloc(sizeof(char) * len)) == NULL
      || strcpy(data, message) == NULL
      || (injector = injectbuf_create(data, len - 1)) == NULL
      || list_push_back(&client->outbound, injector) == false)
    {
      printf_error("failed to write %s to %s:%d", message,
		   client->ip, client->port);
      return (false);
    }
  data[len - 2] = '\n';
  data[len - 1] = '\0';
  return (true);
}
