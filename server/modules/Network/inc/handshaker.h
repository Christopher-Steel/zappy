/*
** handshaker.h for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Network/inc
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:30:02 2014 Valentin
** Last update Sun Jul 13 19:30:09 2014 Valentin
*/

#ifndef		HANDSHAKER_H_
# define	HANDSHAKER_H_

# include	"network_client.h"

typedef struct	s_handshaker
{
  void		(*receive)(t_receiver *rec, char *msg);
  void		(*destroy)(t_receiver *rec);
  t_client	*client;
}	        t_handshaker;

t_handshaker	*handshaker_create(t_client *client)
  __attribute__ ((nonnull));

#endif		/* HANDSHAKER_H_ */
