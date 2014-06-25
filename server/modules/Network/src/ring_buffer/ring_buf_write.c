#include <unistd.h>

#include "ring_buf.h"
#include "zappy_types.h"

int		ring_buf_write(t_ring_buf *ring, int fd)
{
  int		rc;
  int		len;

  if (ring->tail <= ring->head && ring->len)
    {
      if ((len = write(fd, &ring->buf[ring->head],
		       RING_BUF_SIZE - ring->head)) == -1)
	return (-1);
      ring->head = ((uint)len < RING_BUF_SIZE - ring->head
		    ? ring->head + len : 0);
      ring->len -= len;
      if ((rc = ring_buf_write(ring, fd)) == -1)
	return (-1);
      len += rc;
    }
  else
    {
      if ((len = write(fd, &ring->buf[ring->head], ring->len)) == -1)
	return (-1);
      ring->head += len;
      ring->len -= len;
    }
  return (len);
}
