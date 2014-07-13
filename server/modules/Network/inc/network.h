/*
** network.h for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Network/inc
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:30:33 2014 Valentin
** Last update Sun Jul 13 19:30:34 2014 Valentin
*/

#ifndef		NETWORK_H_
# define	NETWORK_H_

# include	"socket_pool.h"

# define	LISTEN_Q_SIZE	20

typedef struct	s_network
{
  t_sockpool	pool;
}		t_network;

bool		network_init(int port);
void		network_update(void);
void		network_shutdown(void);

#endif		/* NETWORK_H_ */
