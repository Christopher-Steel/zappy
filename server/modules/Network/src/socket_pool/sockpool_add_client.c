#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#include "print_error.h"
#include "print_log.h"
#include "server.h"
#include "socket_pool.h"
#include "zappy_types.h"

static void	count_clients(__attribute__ ((unused))void *data,
			      void *accumulator)
{
  ++(*((uint *)accumulator));
}

static bool	fd_available(t_sockpool *pool)
{
  struct rlimit	limit;
  uint		nb_clients;

  nb_clients = 0;
  list_for_each_arg(&pool->nodes, &count_clients, &nb_clients);
  if (getrlimit(RLIMIT_NOFILE, &limit) == -1)
    return (print_perror("network failed to get resource limit"));
  else if (nb_clients >= (uint)limit.rlim_cur)
    return (print_error("Cannot accept any more clients, "
			"file descriptor limit exceeded"));
  else
    return (true);
}

static t_sock		accept_client(t_sockpool *pool, t_sock listener,
				      char **ip, int *port)
{
  struct sockaddr_in	sock_addr;
  socklen_t		addrlen;
  t_sock		sock;

  addrlen = sizeof(sock_addr);
  if (fd_available(pool) == false
      || (sock = accept(listener, (struct sockaddr *)&sock_addr,
			&addrlen)) == -1)
    {
      print_perror("Failed to accept new client");
      return (-1);
    }
  *ip = strdup(inet_ntoa(sock_addr.sin_addr));
  *port = sock_addr.sin_port;
  printf_log("New client connected from %s:%d", *ip, *port);
  return (sock);
}

void			sockpool_add_client(t_sockpool *pool, t_sock listener)
{
  t_sock		sock;
  t_sockpool_node	*new_node;
  char			*ip;
  int			port;

  if ((sock = accept_client(pool, listener, &ip, &port)) != -1)
    {
      if ((new_node = sockpool_node_create(sock)) == NULL)
	{
	  print_error("Failed to create new player. Rejected client.");
	  free(ip);
	  close(sock);
	}
      else
	{
	  new_node->ip = ip;
	  new_node->port = port;
	  list_push_front(&pool->nodes, new_node);
	}
    }
}

