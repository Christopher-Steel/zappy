/*
** event_handler.h for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Event/inc
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 18:29:49 2014 Valentin
** Last update Sun Jul 13 18:30:35 2014 Valentin
*/

#ifndef		EVENT_HANDLER_H_
# define	EVENT_HANDLER_H_

typedef struct	s_event	t_event;

typedef struct	s_event_handler
{
  void		(*spacing[2])(void);
  void		(*event_handler)(t_event *);
}		t_event_handler;

#endif		/* !EVENT_HANDLER_H_ */
