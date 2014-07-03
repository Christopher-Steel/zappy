#include "ring_buf.h"

bool	ring_buf_empty(t_ring_buf *ring)
{
  return ((ring->len == 0));
}
