#include <unistd.h>

#include "ring_buf.h"

static int	ring_buf_read_part(t_ring_buf *ring, int fd, int space)
{
  int		pushed;

  if ((pushed = read(fd, &ring->buf[ring->tail], space)) > 0)
    ring->len += pushed;
  return (pushed);
}

int		ring_buf_read(t_ring_buf *ring, int fd)
{
  int		space;
  int		pushed;
  int		total_pushed;

  total_pushed = 0;
  if (ring->head < ring->tail || (ring->head == ring->tail && !ring->len))
    {
      space = RING_BUF_SIZE - ring->tail;
      if ((pushed = ring_buf_read_part(ring, fd, space)) <= 0)
	return (pushed);
      if (pushed == space)
	ring->tail = 0;
      else
	ring->tail += pushed;
      if (pushed < space)
	return (pushed);
      total_pushed += pushed;
    }
  space = ring->head;
  if ((pushed = ring_buf_read_part(ring, fd, space)) <= 0)
    return (pushed);
  ring->tail += pushed;
  return (pushed + total_pushed);
}
