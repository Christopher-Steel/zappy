/*
** tcp_sock_get_addr.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Network/src/tcp_socket
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:43:54 2014 Valentin
** Last update Sun Jul 13 19:44:00 2014 Valentin
*/

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
