/*
** tcp_socket.h for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Network/inc
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:19:57 2014 Valentin
** Last update Sun Jul 13 19:19:59 2014 Valentin
*/

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
