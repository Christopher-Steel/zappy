/*
** equal_vector.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Vector/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:16:15 2014 Valentin
** Last update Sun Jul 13 19:16:16 2014 Valentin
*/

#include "vector.h"

bool	equal_vector(t_vector vec1, t_vector vec2)
{
  if (vec1.x == vec2.x && vec1.y == vec2.y)
    return (true);
  return (false);
}
