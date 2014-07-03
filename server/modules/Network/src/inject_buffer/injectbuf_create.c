#include <stdlib.h>

#include "inject_buffer.h"
#include "print_error.h"

t_injectbuf	*injectbuf_create(char *data, uint len)
{
  t_injectbuf	*newbuf;

  if ((newbuf = malloc(sizeof(*newbuf))) == NULL)
    {
      print_perror("failed to allocate new buffer");
      return (NULL);
    }
  newbuf->data = data;
  newbuf->head = 0;
  newbuf->len = len;
  return (newbuf);
}
