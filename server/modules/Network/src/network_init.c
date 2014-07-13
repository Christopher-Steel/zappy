/*
** network_init.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Network/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:32:11 2014 Valentin
** Last update Sun Jul 13 19:32:11 2014 Valentin
*/

#include "print_log.h"
#include "network.h"
#include "server.h"

bool		network_init(int port)
{
  t_sockpool	*pool;
  int		rc;

  print_log("Initializing network...");
  pool = &g_server.network.pool;
  pool->listener = -1;
  if ((rc = tcp_sock_passive_init(&pool->listener, port, LISTEN_Q_SIZE)))
    printf_log("Network initialized. Listening on port %d", port);
  else
    print_log("Failed to initialize network.");
  return (rc);
}
