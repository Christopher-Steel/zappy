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
