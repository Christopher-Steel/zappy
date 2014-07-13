/*
** gs_get_map_width.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 18:13:05 2014 Valentin
** Last update Sun Jul 13 18:13:07 2014 Valentin
*/

#include "server.h"

unsigned int	gs_get_map_width(void)
{
  return (g_server.world.width);
}
