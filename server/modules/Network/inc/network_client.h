#ifndef		NETWORK_CLIENT_H_
# define	NETWORK_CLIENT_H_

# include	"socket_pool.h"

typedef		t_sockpool_node	t_client;

bool		client_write_to(t_client *client, char *message)
  __attribute__ ((nonnull));
void		client_close(t_client *client)
  __attribute__ ((nonnull));
void		client_shutdown(t_client *client)
  __attribute__ ((nonnull));


#endif		/* NETWORK_CLIENT_H_ */
