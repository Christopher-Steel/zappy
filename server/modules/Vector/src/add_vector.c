/*
** add_vector.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Vector/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:16:26 2014 Valentin
** Last update Sun Jul 13 19:16:27 2014 Valentin
*/

#include "vector.h"

t_vector	add_vector(t_vector vec1, t_vector vec2)
{
  t_vector	vec3;

  vec3.x = vec1.x + vec2.x;
  vec3.y = vec1.y + vec2.y;
  return (vec3);
}
