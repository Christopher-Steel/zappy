#include <unistd.h>

#include "ring_buf.h"

static int	ring_buf_read_part(t_ring_buf *ring, int fd, int space)
{
  int		pushed;

  if ((pushed = read(fd, &ring->buf[ring->tail], space)) > 0)
    ring->len += pushed;
  return (pushed);
}

int	ring_buf_read(t_ring_buf *ring, int fd)
{
  int	pushed;
  uint	size;

  if (ring->tail >= ring->head)
    {
      size = RING_BUF_SIZE - ring->tail;
      if ((pushed = ring_buf_read_part(ring, fd, size)) == -1)
	return (-1);
      ring->tail = ((uint)pushed == size ? 0 : ring->tail + pushed);
    }
  else
    {
      size = ring->head - ring->tail;
      if ((pushed = ring_buf_read_part(ring, fd, size)) == -1)
	return (-1);
      ring->tail += pushed;
    }
  return (pushed);
}
