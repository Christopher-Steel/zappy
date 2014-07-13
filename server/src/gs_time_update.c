/*
** gs_time_update.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 18:12:28 2014 Valentin
** Last update Sun Jul 13 18:12:29 2014 Valentin
*/

#include <sys/time.h>

#include "server.h"

void			gs_time_update(void)
{
  struct timeval	tv;
  long double		time;

  gettimeofday(&tv, NULL);
  time = tv.tv_sec + (tv.tv_usec * 0.000001);
  if (g_server.info.time != 0)
    {
      g_server.info.dtime = time - g_server.info.time;
      g_server.info.dtime *= g_server.info.tick_delay;
    }
  g_server.info.total_ticks += g_server.info.dtime;
  g_server.info.time = time;
}
