/*
** gs_get_map_height.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 18:12:58 2014 Valentin
** Last update Sun Jul 13 18:12:59 2014 Valentin
*/

#include "server.h"

unsigned int	gs_get_map_height(void)
{
  return (g_server.world.height);
}
