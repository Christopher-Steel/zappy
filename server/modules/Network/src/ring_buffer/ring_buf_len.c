#include "ring_buf.h"

unsigned int	ring_buf_len(t_ring_buf *ring)
{
  if (!ring)
    return (0);
  return (ring->len);
}
