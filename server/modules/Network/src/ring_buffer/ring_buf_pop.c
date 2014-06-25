#include <stdlib.h>

#include "print_error.h"
#include "ring_buf.h"
#include "zappy_types.h"

/* ring->head < ring->tail
	 || (ring->head == ring->tail && ring->len > 0)
	 || (ring->tail == 0)*/

static int	ring_buf_simple_pop(t_ring_buf *ring, char *dest)
{
  uint		index;

  for (index = 0; ring->len > 0; ++ring->head)
    {
      if (ring->buf[ring->head] == '\n')
	{
	  ++ring->head;
	  --ring->len;
	  break ;
	}
      dest[index] = ring->buf[ring->head];
      ++index;
      --ring->len;
    }
  dest[index] = '\0';
  return (index);
}

static int	ring_buf_wrap_pop(t_ring_buf *ring, char *dest)
{
  uint		index;

  for (index = 0; ring->head < RING_BUF_SIZE; ++ring->head)
    {
      if (ring->buf[ring->head] == '\n')
	{
	  ++ring->head;
	  --ring->len;
	  break ;
	}
      dest[index] = ring->buf[ring->head];
      --ring->len;
    }
  return (index + ring_buf_simple_pop(ring, &dest[index]));
}

int	ring_buf_pop(t_ring_buf *ring, char *dest)
{
  if (ring->tail <= ring->head
      && ring->len && ring->head > 0
      && ring->tail != 0)
    return (ring_buf_wrap_pop(ring, dest));
  else
    return (ring_buf_simple_pop(ring, dest));
}

int	ring_buf_pop_alloc(t_ring_buf *ring, char **dest)
{
  if ((*dest = malloc((ring->len + 1) * sizeof(**dest))) == NULL)
    {
      print_perror("failed to allocate new string");
      return (-1);
    }
  else
    return (ring_buf_pop(ring, *dest));
}
