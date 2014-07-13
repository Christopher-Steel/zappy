/*
** receiver.h for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Network/inc
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:29:39 2014 Valentin
** Last update Sun Jul 13 19:29:40 2014 Valentin
*/

#ifndef		RECEIVER_H_
# define	RECEIVER_H_

typedef struct	s_receiver
{
  void		(*receive)(struct s_receiver *rec, char *msg);
  void		(*destroy)(struct s_receiver *rec);
}		t_receiver;

#endif		/* RECEIVER_H_ */
