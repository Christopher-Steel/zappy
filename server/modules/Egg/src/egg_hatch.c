#include "egg.h"

bool	egg_hatch(void *egg, __attribute__ ((unused))void *unused)
{
  ++(((t_egg *)egg)->team->free_slots);
  return (true);
}
