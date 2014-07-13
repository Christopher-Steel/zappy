/*
** egg_event_handler.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Egg/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 18:29:04 2014 Valentin
** Last update Sun Jul 13 18:29:05 2014 Valentin
*/

#include "egg.h"
#include "event.h"

void	egg_event_handler(t_event *event)
{
  event->func(event->data, event->arg);
}
