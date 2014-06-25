#include <string.h>

#include "ring_buf.h"

static int	ring_buf_push_part(t_ring_buf *ring, char *str, int space)
{
  int		pushed;
  int		len;

  len = strlen(str);
  pushed = (len < space ? len : space);
  memcpy(&ring->buf[ring->tail], str, pushed);
  ring->len += pushed;
  return (pushed);
}

int		ring_buf_push(t_ring_buf *ring, char *str)
{
  int		space;
  int		pushed;
  int		total_pushed;

  total_pushed = 0;
  if (ring->head < ring->tail || (ring->head == ring->tail && !ring->len))
    {
      space = RING_BUF_SIZE - ring->tail;
      if ((pushed = ring_buf_push_part(ring, str, space)) == space)
	ring->tail = 0;
      else
	ring->tail += pushed;
      str += pushed;
      if (pushed < space)
	return (pushed);
      total_pushed += pushed;
    }
  space = ring->head;
  pushed = ring_buf_push_part(ring, str, space);
  ring->tail += pushed;
  return (pushed + total_pushed);
}
