#include <unistd.h>

#include "inject_buffer.h"
#include "print_error.h"

int	injectbuf_write(t_injectbuf *buf, int fd)
{
  int	len;

  if ((len = write(fd, &buf->data[buf->head], buf->len)) == -1)
    {
      print_perror("failed to write buffer");
      return (-1);
    }
  buf->head += len;
  buf->len -= len;
  return (len);
}
