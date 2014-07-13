/*
** client_shutdown.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Network/src/client
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:32:59 2014 Valentin
** Last update Sun Jul 13 19:32:59 2014 Valentin
*/

#include <unistd.h>

#include "network_client.h"
#include "print_log.h"
#include "server.h"

void	client_shutdown(t_client *client)
{
  printf_log("Client %s:%d disconnected", client->ip, client->port);
  close(client->socket);
  free(client->ip);
  if (client->receiver)
    client->receiver->destroy(client->receiver);
  list_clear(&client->inbound, true);
  list_clear(&client->outbound, true);
  list_remove(&g_server.network.pool.nodes, client, true);
}
