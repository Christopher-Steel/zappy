/*
** graphic_manager_init.c for zappy in /home/launoi_a/tmp/PSU_2013_zappy/server/modules/Graphic
** 
** Made by allyriane.launois
** Login   <launoi_a@epitech.net>
** 
** Started on  Sun Jul 13 18:39:05 2014 allyriane.launois
** Last update Sun Jul 13 18:39:12 2014 allyriane.launois
*/

#include "graphic.h"
#include "print_log.h"
#include "server.h"

void		graphic_manager_init(void)
{
  t_list	*list;

  print_log("Initializing graphic manager...");
  list = &g_server.graphic_manager.graphic_handlers;
  list->size = 0;
  list->nodes = NULL;
  list->last = NULL;
  print_log("Graphic manager initialized.");
}
