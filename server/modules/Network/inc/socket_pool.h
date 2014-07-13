/*
** socket_pool.h for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Network/inc
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:28:09 2014 Valentin
** Last update Sun Jul 13 19:28:10 2014 Valentin
*/

#ifndef		SOCKET_POOL_H_
# define	SOCKET_POOL_H_

# include	<sys/select.h>
# include	<sys/types.h>
# include	<sys/time.h>

# include	"list.h"
# include	"receiver.h"
# include	"ring_buf.h"
# include	"tcp_socket.h"
# include	"zappy_types.h"

# define	FILTER_TIMEOUT_S	0
# define	FILTER_TIMEOUT_MS	50

typedef struct	s_sockpool
{
  fd_set	read_set;
  fd_set	write_set;
  uint		maxfd;
  int		nbset;

  t_list	broadcast;

  t_sock	listener;
  t_list	nodes;
}		t_sockpool;

typedef struct	s_sockpool_node
{
  t_receiver	*receiver;
  t_sock	socket;
  char		*ip;
  int		port;

  bool		closing;

  t_ring_buf	read;
  t_ring_buf	write;

  t_list	inbound;
  t_list	outbound;
}		t_sockpool_node;

void		sockpool_push(t_sockpool *pool, void *data, t_sock socket)
  __attribute__ ((nonnull(1)));
void		sockpool_erase(t_sockpool *pool, t_sockpool_node *node)
  __attribute__ ((nonnull));

void		sockpool_fill_sets(t_sockpool *pool)
  __attribute__ ((nonnull));
bool		sockpool_filter(t_sockpool *pool, struct timeval *t)
  __attribute__ ((nonnull(1)));
void		sockpool_handle(t_sockpool *pool)
  __attribute__ ((nonnull));
void		sockpool_update(t_sockpool *pool)
  __attribute__ ((nonnull));

t_sockpool_node	*sockpool_node_create(t_sock sock);

void		sockpool_add_client(t_sockpool *pool, t_sock listener)
  __attribute__ ((nonnull(1)));
int		sockpool_node_read(t_sockpool_node *node)
  __attribute__ ((nonnull));
int		sockpool_node_write(t_sockpool_node *node)
  __attribute__ ((nonnull));

#endif		/* SOCKET_POOL_H_ */
