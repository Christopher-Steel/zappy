/*
** ring_buf_write.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Network/src/ring_buffer
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:35:35 2014 Valentin
** Last update Sun Jul 13 19:35:45 2014 Valentin
*/

#include <unistd.h>

#include "ring_buf.h"
#include "zappy_types.h"

int	ring_buf_write(t_ring_buf *ring, int fd)
{
  int	len;

  if (ring->tail <= ring->head && ring->len)
    {
      if ((len = write(fd, &ring->buf[ring->head],
		       RING_BUF_SIZE - ring->head)) == -1)
	return (-1);
      ring->head = ((uint)len < RING_BUF_SIZE - ring->head
		    ? ring->head + len : 0);
      ring->len -= len;
    }
  else
    {
      if ((len = write(fd, &ring->buf[ring->head], ring->len)) == -1)
	return (-1);
      ring->head += len;
      ring->len -= len;
    }
  return (len);
}
