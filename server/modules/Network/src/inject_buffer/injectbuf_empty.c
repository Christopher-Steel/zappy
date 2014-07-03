#include "inject_buffer.h"
#include "print_debug.h"

bool	injectbuf_empty(t_injectbuf *buf)
{
  return ((buf->len > 0 ? false : true));
}
