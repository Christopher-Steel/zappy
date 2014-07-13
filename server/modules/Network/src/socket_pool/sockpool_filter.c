/*
** sockpool_filter.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Network/src/socket_pool
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:39:50 2014 Valentin
** Last update Sun Jul 13 19:39:51 2014 Valentin
*/

#include "socket_pool.h"

bool	sockpool_filter(t_sockpool *pool, struct timeval *time)
{
  return (((pool->nbset = select(pool->maxfd + 1, &pool->read_set,
				 &pool->write_set, NULL, time)) == -1
	   ? false : true));
}
