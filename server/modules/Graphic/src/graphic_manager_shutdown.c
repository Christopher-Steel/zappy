/*
** graphic_manager_shutdown.c for zappy in /home/launoi_a/tmp/PSU_2013_zappy/server/modules/Graphic
** 
** Made by allyriane.launois
** Login   <launoi_a@epitech.net>
** 
** Started on  Sun Jul 13 18:39:21 2014 allyriane.launois
** Last update Sun Jul 13 18:39:27 2014 allyriane.launois
*/

#include "graphic.h"
#include "print_log.h"
#include "server.h"

void	graphic_manager_shutdown(void)
{
  print_log("Shutting down graphic manager...");
  list_clear(&g_server.graphic_manager.graphic_handlers, true);
}
