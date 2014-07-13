/*
** network_broadcast.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Network/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:31:55 2014 Valentin
** Last update Sun Jul 13 19:32:04 2014 Valentin
*/

#include "network.h"
#include "server.h"

void	network_broadcast(char *msg)
{
  list_push_back(&g_server.network.pool.broadcast, msg);
}
