/*
** network_client.h for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Network/inc
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:29:48 2014 Valentin
** Last update Sun Jul 13 19:29:49 2014 Valentin
*/

#ifndef		NETWORK_CLIENT_H_
# define	NETWORK_CLIENT_H_

# include	"socket_pool.h"

typedef		t_sockpool_node	t_client;

bool		client_write_to(t_client *client, char *message)
  __attribute__ ((nonnull));
void		client_close(t_client *client)
  __attribute__ ((nonnull));
void		client_shutdown(t_client *client)
  __attribute__ ((nonnull));

#endif		/* NETWORK_CLIENT_H_ */
