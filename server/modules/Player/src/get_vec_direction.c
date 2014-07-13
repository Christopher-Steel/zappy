/*
** get_vec_direction.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Player/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:05:59 2014 Valentin
** Last update Sun Jul 13 19:06:00 2014 Valentin
*/

#include "player.h"

t_vector	get_vec_direction(enum e_ori ori)
{
  t_vector	tab[] =
    {
      {0, -1},
      {1, 0},
      {0, 1},
      {-1, 0}
    };

  return (tab[ori]);
}
