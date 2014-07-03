#ifndef		NETWORK_H_
# define	NETWORK_H_

# include	"socket_pool.h"

# define	LISTEN_Q_SIZE	20

typedef struct	s_network
{
  t_sockpool	pool;
}		t_network;

bool		network_init(int);
void		network_update(void);
void		network_shutdown(int, void *);

#endif		/* NETWORK_H_ */
