
#ifndef		EVENT_H_
# define	EVENT_H_

# include	"player.h"
# include	"team.h"
# include	"zappy_types.h"

typedef bool	(*func_ptr)(t_player *player, void *arg);

typedef struct	s_event
{
  t_player	*player;
  func_ptr	func;
  long double	timestamp;
  void		*arg;
}		t_event;

typedef struct	s_event_manager
{
  t_event	**event;
  int		size;
}		t_event_manager;

t_event		*event_create(t_player *player, func_ptr func,
			      long double timestamp, void *arg);
t_event		*event_destroy(t_event *event);

void		event_add(t_list *events, t_event *event);

void		event_update(t_list *event);

#endif		/* !EVENT_H_ */
