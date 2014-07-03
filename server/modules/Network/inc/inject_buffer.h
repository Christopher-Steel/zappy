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
