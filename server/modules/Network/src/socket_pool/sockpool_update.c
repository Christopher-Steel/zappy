/*
** sockpool_update.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Network/src/socket_pool
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:38:03 2014 Valentin
** Last update Sun Jul 13 19:38:11 2014 Valentin
*/

#include "print_warning.h"
#include "socket_pool.h"

void			sockpool_update(t_sockpool *pool)
{
  struct timeval	t;

  t.tv_sec = FILTER_TIMEOUT_S;
  t.tv_usec = FILTER_TIMEOUT_MS;
  sockpool_fill_sets(pool);
  if (sockpool_filter(pool, &t) != -1)
    sockpool_handle(pool);
  else
    print_pwarning("network sockpool filtering failed");
}
