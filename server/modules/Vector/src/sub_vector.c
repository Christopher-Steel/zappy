#include "vector.h"

t_vector	sub_vector(t_vector vec1, t_vector vec2)
{
  t_vector	vec3;

  vec3.x = vec1.x - vec2.x;
  vec3.y = vec1.y - vec2.y;
  return (vec3);
}
