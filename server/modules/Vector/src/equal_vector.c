#include "vector.h"

bool	equal_vector(t_vector vec1, t_vector vec2)
{
  if (vec1.x == vec2.x && vec1.y == vec2.y)
    return (true);
  return (false);
}
