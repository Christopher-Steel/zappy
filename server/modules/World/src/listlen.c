#include "world.h"

unsigned int	listlen(t_list_player *list)
{
  t_list_player	*tmp;
  unsigned int	i;

  i = 0;
  tmp = list;
  while (tmp != NULL)
    {
      tmp = tmp->next;
      ++i;
    }
  return (i);
}
