/*
** egg_hatch.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Egg/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 18:28:44 2014 Valentin
** Last update Sun Jul 13 18:28:52 2014 Valentin
*/

#include "egg.h"
#include "graph_PI.h"
#include "print_log.h"

bool	egg_hatch(void *data, __attribute__ ((unused))void *unused)
{
  t_egg	*egg;

  egg = (t_egg *)data;
  egg->is_hatches = true;
  ++egg->team->free_slots;
  printf_log("Egg %d hatched in %d/%d", egg->id, egg->pos.x, egg->pos.y);
  graph_for_each_1_arg(&graphic_eht, egg);
  return (true);
}
