/*
** network_update.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Network/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:31:12 2014 Valentin
** Last update Sun Jul 13 19:31:13 2014 Valentin
*/

#include "network.h"
#include "server.h"

void	network_update(void)
{
  sockpool_update(&g_server.network.pool);
}
