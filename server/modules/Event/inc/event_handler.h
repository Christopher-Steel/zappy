#ifndef		EVENT_HANDLER_H_
# define	EVENT_HANDLER_H_

typedef struct	s_event	t_event;

typedef struct	s_event_handler
{
  void		(*spacing[2])(void);
  void		(*event_handler)(t_event *);
}		t_event_handler;

#endif		/* EVENT_HANDLER_H_ */
