#include <stdlib.h>

#include "inject_buffer.h"

void	injectbuf_destroy(t_injectbuf *buf, bool data)
{
  if (data)
    free(buf->data);
  free(buf);
}
