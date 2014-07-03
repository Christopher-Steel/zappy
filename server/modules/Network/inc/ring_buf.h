#ifndef		RING_BUF_H_
# define	RING_BUF_H_

# define	RING_BUF_SIZE	2048

# include	"zappy_types.h"

typedef struct	s_ring_buf
{
  char		buf[RING_BUF_SIZE];
  uint		head;
  uint		tail;
  uint		len;
}		t_ring_buf;

void		ring_buf_ctor(t_ring_buf *ring)
  __attribute__ ((nonnull));

t_ring_buf	*ring_buf_create(void);

uint		ring_buf_len(t_ring_buf *ring)
  __attribute__ ((nonnull));
bool		ring_buf_empty(t_ring_buf *ring)
  __attribute__ ((nonnull));

int		ring_buf_push(t_ring_buf *ring, char *str)
  __attribute__ ((nonnull));
int		ring_buf_pop(t_ring_buf *ring, char *dest)
  __attribute__ ((nonnull));
int		ring_buf_pop_alloc(t_ring_buf *ring, char **dest)
  __attribute__ ((nonnull));

int		ring_buf_read(t_ring_buf *ring, int fd)
  __attribute__ ((nonnull));
int		ring_buf_write(t_ring_buf *ring, int fd)
  __attribute__ ((nonnull));

#endif		/* RING_BUF_H_ */
