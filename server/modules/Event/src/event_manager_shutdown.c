/*
** event_manager_shutdown.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Event/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 18:32:02 2014 Valentin
** Last update Sun Jul 13 18:32:02 2014 Valentin
*/

#include "event.h"
#include "print_log.h"
#include "server.h"

void	event_manager_shutdown(void)
{
  print_log("Shutting down event manager...");
  list_clear(&g_server.event_manager.events, true);
}
