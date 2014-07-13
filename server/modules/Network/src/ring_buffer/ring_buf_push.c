/*
** ring_buf_push.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Network/src/ring_buffer
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:37:14 2014 Valentin
** Last update Sun Jul 13 19:37:33 2014 Valentin
*/

#include <string.h>

#include "ring_buf.h"

static int	ring_buf_push_part(t_ring_buf *ring, char *str, int space)
{
  int		pushed;
  int		len;

  len = strlen(str);
  pushed = (len < space ? len : space);
  memcpy(&ring->buf[ring->tail], str, pushed);
  ring->len += pushed;
  return (pushed);
}

int	ring_buf_push(t_ring_buf *ring, char *str)
{
  int	space;
  int	pushed;
  int	total_pushed;

  total_pushed = 0;
  if (ring->head < ring->tail || (ring->head == ring->tail && !ring->len))
    {
      space = RING_BUF_SIZE - ring->tail;
      if ((pushed = ring_buf_push_part(ring, str, space)) == space)
	ring->tail = 0;
      else
	ring->tail += pushed;
      str += pushed;
      if (pushed < space)
	return (pushed);
      total_pushed += pushed;
    }
  space = ring->head;
  pushed = ring_buf_push_part(ring, str, space);
  ring->tail += pushed;
  return (pushed + total_pushed);
}
