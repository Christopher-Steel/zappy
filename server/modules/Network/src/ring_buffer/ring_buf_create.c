#include <stdlib.h>

#include "ring_buf.h"

t_ring_buf	*ring_buf_create(void)
{
  t_ring_buf	*new_ring;

  if ((new_ring = malloc(sizeof(*new_ring))) == NULL)
    return (NULL);
  ring_buf_ctor(new_ring);
  return (new_ring);
}
