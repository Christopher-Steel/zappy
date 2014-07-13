/*
** egg_create_destroy.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Egg/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 18:29:15 2014 Valentin
** Last update Sun Jul 13 18:29:16 2014 Valentin
*/

#include <stdlib.h>

#include "egg.h"
#include "print_error.h"

t_egg	*egg_create(int id, t_team *team)
{
  t_egg	*egg;

  if (!(egg = malloc(sizeof(t_egg))))
    {
      print_perror("failed to allocate new egg");
      return (NULL);
    }
  egg->is_hatches = false;
  egg->event_handler = &egg_event_handler;
  egg->id = id;
  egg->team = team;
  return (egg);
}

void	egg_destroy(t_egg *egg)
{
  free(egg);
}
