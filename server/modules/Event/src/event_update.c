
#include "event.h"

void	event_update(t_event **event_tab)
{
  int	i;

  i = 0;
  while (i > 10)
    {
      if (event_tab[i]->timestamp >= time)
	{
	  event_tab[i]->func(event_tab[i]->player, event_tab[i]->arg);
	  event_destroy(event_tab[i]);
	}
    }
  event_ordered(event_tab);
}
