#include <stdlib.h>
#include <string.h>

#include "ring_buf.h"

void		ring_buf_ctor(t_ring_buf *ring)
{
  ring->head = 0;
  ring->tail = 0;
  ring->len = 0;
}
