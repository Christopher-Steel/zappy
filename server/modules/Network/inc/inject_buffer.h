/*
** inject_buffer.h for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Network/inc
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:30:22 2014 Valentin
** Last update Sun Jul 13 19:30:23 2014 Valentin
*/

#ifndef		INJECT_BUFFER_H_
# define	INJECT_BUFFER_H_

# include	"ring_buf.h"

typedef struct	s_injectbuf
{
  char		*data;
  uint		head;
  uint		len;
}		t_injectbuf;

t_injectbuf	*injectbuf_create(char *data, uint len)
  __attribute__ ((nonnull));
void		injectbuf_destroy(t_injectbuf *buf, bool data)
  __attribute__ ((nonnull));

int		injectbuf_write(t_injectbuf *buf, int fd)
  __attribute__ ((nonnull));
bool		injectbuf_ring_inject(t_injectbuf *buf, t_ring_buf *ring)
  __attribute__ ((nonnull));
bool		injectbuf_empty(t_injectbuf *buf)
  __attribute__ ((nonnull));

#endif		/* INJECT_BUFFER_H_ */
