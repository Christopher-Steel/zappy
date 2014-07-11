#ifndef		EVENT_HANDLER_H_
# define	EVENT_HANDLER_H_

typedef struct	s_event_handler
{
  void		(*spacing[2])(void);
  void		(*event_handler)(struct s_event_handler *handler);
}		t_event_handler;

#endif		/* EVENT_HANDLER_H_ */
