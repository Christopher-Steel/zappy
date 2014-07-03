#ifndef		TCP_SOCKET_H_
# define	TCP_SOCKET_H_

# include	<sys/socket.h>
# include	<netdb.h>

# include	"zappy_types.h"

typedef struct	s_sock_info
{
  char		*ip;
  int		port;
}		t_sock_info;

t_sock		tcp_sock_create(void);
struct sockaddr	*tcp_sock_get_addr(struct sockaddr_in *, in_addr_t, int);
bool		tcp_sock_passive_init(t_sock *, int, int);
bool		tcp_sock_active_init(t_sock *, char *, int);

#endif		/* TCP_SOCKET_H_ */
