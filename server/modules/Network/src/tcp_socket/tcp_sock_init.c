#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include "print_error.h"
#include "tcp_socket.h"

static bool	tcp_sock_set_reusable(t_sock *sock, bool reusable)
{
  int		optVal;

  optVal = (reusable ? 1 : 0);
  if (setsockopt(*sock, SOL_SOCKET, SO_REUSEADDR,
		 (void *)&optVal, sizeof(optVal)) == -1)
    {
      close(*sock);
      print_perror("failed to set socket reusability");
      return (false);
    }
  return (true);
}

/*
** These functions are callable in two different ways
** depending on what the first argument is :
**   - a pointer to t_sock returned by tcp_sock_create()
**   - a pointer to a t_sock set to -1
**
** If the socket received as argument was not a
** pre-created socket then these functions will create one
** before initializing it and storing it in the pointer.
**
** Also, if either of theses functions fail, the socket will
** be closed and no longer valid.
*/
bool			tcp_sock_passive_init(t_sock *sock, int port,
					      int nbClients)
{
  struct sockaddr_in	sock_addr;

  if ((*sock == -1 && (*sock = tcp_sock_create()) == -1)
      || tcp_sock_get_addr(&sock_addr, INADDR_ANY, port) == NULL)
    return (false);
  if (bind(*sock, (const struct sockaddr *)&sock_addr,
	   sizeof(sock_addr)) == -1)
    {
      close(*sock);
      return (print_perror("failed to bind socket to address"));
    }
  if (tcp_sock_set_reusable(sock, true) == false)
    return (false);
  if (nbClients == 0 || listen(*sock, nbClients) == -1)
    {
      close(*sock);
      return (print_perror("failed to set socket as passive"));
    }
  return (true);
}

bool			tcp_sock_active_init(t_sock *sock, char *host,
					     int port)
{
  struct sockaddr_in	sock_addr;

  if ((*sock == -1 && (*sock = tcp_sock_create()) == -1)
      || tcp_sock_get_addr(&sock_addr, inet_addr(host), port) == NULL)
    return (false);
  if (connect(*sock, (const struct sockaddr *)&sock_addr,
	      sizeof(sock_addr)) == -1)
    {
      close(*sock);
      return (print_perror("socket connection failed"));
    }
  return (true);
}
