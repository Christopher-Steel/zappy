
#include <stdlib.h>

#include "egg.h"

t_egg	*egg_create(int id, t_team *team)
{
  t_egg	*egg;

  if (!(egg = malloc(sizeof(t_egg))))
    {
      print_perror("malloc");
      return (NULL);
    }
  egg->id = id;
  egg->team = team;
  return (egg);
}

void	egg_destroy(t_egg *egg)
{
  free(egg);
}
