/*
** event.h for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Event/inc
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 18:30:55 2014 Valentin
** Last update Sun Jul 13 18:30:56 2014 Valentin
*/

#ifndef		EVENT_H_
# define	EVENT_H_

# include	"event_handler.h"
# include	"list.h"
# include	"player.h"
# include	"team.h"
# include	"zappy_types.h"

typedef struct	s_event_manager
{
  t_list	events;
}		t_event_manager;

void		event_manager_init(void);
void		event_manager_shutdown(void);

typedef struct		s_event
{
  t_event_handler	*data;
  t_pl_func		func;
  long double		timestamp;
  void			*arg;
}			t_event;

t_event		*event_create(t_event_handler *data, t_pl_func func,
			      long double timestamp, void *arg);
void		event_add(t_list *events, t_event *event);
void		event_update(t_list *event);

void		gs_event_add(t_event *event);
void		gs_event_update(void);

#endif		/* !EVENT_H_ */
