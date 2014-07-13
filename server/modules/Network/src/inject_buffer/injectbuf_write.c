/*
** injectbuf_write.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Network/src/inject_buffer
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:34:23 2014 Valentin
** Last update Sun Jul 13 19:34:24 2014 Valentin
*/

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
