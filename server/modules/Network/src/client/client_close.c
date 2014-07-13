/*
** client_close.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Network/src/client
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:33:15 2014 Valentin
** Last update Sun Jul 13 19:33:16 2014 Valentin
*/

#include "network_client.h"

void	client_close(t_client *client)
{
  client->closing = true;
}
