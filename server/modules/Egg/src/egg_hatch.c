#include "egg.h"
#include "print_log.h"

bool	egg_hatch(void *data, __attribute__ ((unused))void *unused)
{
  t_egg	*egg;

  egg = (t_egg *)data;
  ++egg->team->free_slots;
  printf_log("Egg %d hatched in %d/%d", egg->id, egg->pos.x, egg->pos.y);
  return (true);
}
