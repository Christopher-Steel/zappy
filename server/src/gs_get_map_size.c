/*
** gs_get_map_size.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 18:12:47 2014 Valentin
** Last update Sun Jul 13 18:12:48 2014 Valentin
*/

#include "server.h"

unsigned int	gs_get_map_size(void)
{
  return (g_server.world.size);
}
