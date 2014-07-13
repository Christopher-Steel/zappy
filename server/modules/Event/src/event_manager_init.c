/*
** event_manager_init.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Event/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 18:32:54 2014 Valentin
** Last update Sun Jul 13 18:55:33 2014 Valentin
*/

#include "event.h"
#include "print_log.h"
#include "server.h"

void		event_manager_init(void)
{
  t_list	*list;

  print_log("Initializing event manager...");
  list = &g_server.event_manager.events;
  list->size = 0;
  list->nodes = NULL;
  list->last = NULL;
  print_log("Event manager initialized.");
}
