
#include "event.h"

void		event_ordered(t_event **event_tab)
{
  int		i;
  t_event	*tmp;

  i = -1;
  while (++i < 9)
    {
      if ((!event_tab[i] && event_tab[i + 1])
	  || (event_tab[i + 1]
	      && event_tab[i]->timestamp > event_tab[i + 1]->timestamp))
	{
	  tmp = event_tab[i + 1];
	  event_tab[i + 1] = event_tab[i];
	  event_tab[i] = tmp;
	  i = -1;
	}
    }
}
