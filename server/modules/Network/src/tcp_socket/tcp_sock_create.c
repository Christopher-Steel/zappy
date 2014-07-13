/*
** tcp_sock_create.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Network/src/tcp_socket
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:44:10 2014 Valentin
** Last update Sun Jul 13 19:44:25 2014 Valentin
*/

#include <sys/socket.h>
#include <arpa/inet.h>

#include "print_error.h"
#include "tcp_socket.h"

t_sock		tcp_sock_create(void)
{
  t_sock	sock;

  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
      print_perror("failed to create socket");
      return (-1);
    }
  return (sock);
}
