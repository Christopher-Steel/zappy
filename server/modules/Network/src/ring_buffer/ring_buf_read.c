/*
** ring_buf_read.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Network/src/ring_buffer
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:35:53 2014 Valentin
** Last update Sun Jul 13 19:35:54 2014 Valentin
*/

#include <unistd.h>

#include "ring_buf.h"

static int	ring_buf_read_part(t_ring_buf *ring, int fd, int space)
{
  int		pushed;

  if ((pushed = read(fd, &ring->buf[ring->tail], space)) > 0)
    ring->len += pushed;
  return (pushed);
}

int	ring_buf_read(t_ring_buf *ring, int fd)
{
  int	pushed;
  uint	size;

  if (ring->tail >= ring->head)
    {
      size = RING_BUF_SIZE - ring->tail;
      if ((pushed = ring_buf_read_part(ring, fd, size)) == -1)
	return (-1);
      ring->tail = ((uint)pushed == size ? 0 : ring->tail + pushed);
    }
  else
    {
      size = ring->head - ring->tail;
      if ((pushed = ring_buf_read_part(ring, fd, size)) == -1)
	return (-1);
      ring->tail += pushed;
    }
  return (pushed);
}
