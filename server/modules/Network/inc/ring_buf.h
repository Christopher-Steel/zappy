/*
** ring_buf.h for irc in /home/steel_c/Code/IRC/inc
**
** Made by Christopher Steel
** Login   <steel_c@epitech.net>
**
** Started on  Mon Apr 21 15:02:21 2014 Christopher Steel
** Last update Mon Jun 23 20:12:57 2014 Christopher Steel
*/

#ifndef		RING_BUF_H_
# define	RING_BUF_H_

# define	RING_BUF_SIZE	512

# include	"zappy_types.h"

typedef struct	s_ring_buf
{
  char		buf[RING_BUF_SIZE];
  uint		head;
  uint		tail;
  uint		len;
}		t_ring_buf;

void		ring_buf_ctor(t_ring_buf *ring);
t_ring_buf	*ring_buf_create(void);

uint		ring_buf_len(t_ring_buf *ring);

int		ring_buf_push(t_ring_buf *ring, char *str);
int		ring_buf_pop(t_ring_buf *ring, char *dest);
int		ring_buf_pop_alloc(t_ring_buf *ring, char **dest);

int		ring_buf_read(t_ring_buf *ring, int fd);
int		ring_buf_write(t_ring_buf *ring, int fd);

#endif		/* RING_BUF_H_ */
