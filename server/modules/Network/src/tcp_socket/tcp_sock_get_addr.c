#include "print_error.h"
#include "tcp_socket.h"

struct sockaddr	*tcp_sock_get_addr(struct sockaddr_in *sock_addr,
				   in_addr_t host, int port)
{
  if (sock_addr == NULL)
    print_error("cannot obtain socket address: invalid argument");
  else
    {
      sock_addr->sin_family = AF_INET;
      sock_addr->sin_port = htons(port);
      sock_addr->sin_addr.s_addr = host;
    }
  return ((struct sockaddr *)sock_addr);
}
