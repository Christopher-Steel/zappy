
#ifndef		EVENT_H_
# define	EVENT_H_

# include	"zappy_types.h"
# include	"player.h"
# include	"team.h"

typedef bool (*func_ptr)(t_player*player, void *arg);

typedef struct	s_event
{
  t_player	*player;
  func_ptr	func;
  uint		timestamp;
  void		*arg;
}		t_event;

t_event		*event_create(t_player *player, func_ptr func, uint timestamp,
			      void *arg);
t_event		*event_destroy(t_event *event);

void		event_ordered(t_event **event_tab);

void		event_update(t_event **event_tab);

#endif		/* !EVENT_H_ */
