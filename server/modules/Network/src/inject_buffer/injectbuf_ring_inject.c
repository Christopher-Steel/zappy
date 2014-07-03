#include "inject_buffer.h"

bool		injectbuf_ring_inject(t_injectbuf *buf, t_ring_buf *ring)
{
  int		len;

  len = ring_buf_push(ring, &buf->data[buf->head]);
  buf->len -= len;
  buf->head += len;
  return (injectbuf_empty(buf));
}
