#ifndef		SOCKET_POOL_H_
# define	SOCKET_POOL_H_

# include	<sys/select.h>
# include	<sys/types.h>
# include	<sys/time.h>

# include	"list.h"
# include	"ring_buf.h"
# include	"tcp_socket.h"
# include	"zappy_types.h"

typedef struct	s_sockpool
{
  fd_set	read_set;
  fd_set	write_set;
  uint		maxfd;
  int		nbset;
  t_sock	listener;
  t_list	nodes;
}		t_sockpool;

typedef struct	s_sockpool_node
{
  void		*data;
  t_sock	socket;

  t_ring_buf	read;
  t_ring_buf	write;
}		t_sockpool_node;

void		sockpool_push(t_sockpool *pool, void *data, t_sock socket)
  __attribute__ ((nonnull(1)));

bool		sockpool_filter(t_sockpool *pool, struct timeval *t)
  __attribute__ ((nonnull));
void		sockpool_handle(t_sockpool *pool)
  __attribute__ ((nonnull));

#endif		/* SOCKET_POOL_H_ */
