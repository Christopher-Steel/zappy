#include <sys/socket.h>
#include <arpa/inet.h>

#include "print_error.h"
#include "tcp_socket.h"

t_sock			tcp_sock_create(void)
{
  t_sock		sock;

  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
      print_perror("failed to create socket");
      return (-1);
    }
  return (sock);
}
