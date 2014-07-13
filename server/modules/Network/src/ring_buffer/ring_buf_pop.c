/*
** ring_buf_pop.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Network/src/ring_buffer
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:36:06 2014 Valentin
** Last update Sun Jul 13 19:36:06 2014 Valentin
*/

#include <stdlib.h>
#include <string.h>

#include "print_debug.h"
#include "print_error.h"
#include "ring_buf.h"
#include "zappy_types.h"

static uint	seek_endline(t_ring_buf *ring)
{
  uint		cursor;
  uint		count;

  count = 0;
  if (ring->len == 0)
    return (0);
  for (cursor = ring->head; cursor >= ring->tail
	 && cursor < RING_BUF_SIZE
	 && ring->buf[cursor] != '\n'; ++cursor)
    ++count;
  if (cursor < RING_BUF_SIZE && cursor >= ring->tail
      && ring->buf[cursor] == '\n')
    return ((cursor && ring->buf[cursor - 1] == '\r' ? count - 1 : count));
  for (cursor = (count ? 0 : ring->head); cursor < ring->tail
	 && ring->buf[cursor] != '\n'; ++cursor)
    ++count;
  if (cursor < ring->tail && ring->buf[cursor] == '\n')
    return ((cursor && ring->buf[cursor - 1] == '\r' ? count - 1 : count));
  else
    return (0);
}

static void	move_to_next_non_endline(t_ring_buf *ring)
{
  while ((ring->buf[ring->head] == '\n' || ring->buf[ring->head] == '\r')
	 && ring->len > 0)
    {
      ++ring->head;
      --ring->len;
    }
}

static void	transfer_data(t_ring_buf *ring, char *dest, uint len)
{
  uint		size;

  if (ring->head + len >= RING_BUF_SIZE)
    {
      size = RING_BUF_SIZE - ring->head;
      memcpy(dest, &ring->buf[ring->head], size);
      len -= size;
      ring->len -= size;
      ring->head = 0;
      dest += size;
    }
  memcpy(dest, &ring->buf[ring->head], len);
  dest[len] = '\0';
  ring->len -= len;
  ring->head += len;
  move_to_next_non_endline(ring);
}

int	ring_buf_pop(t_ring_buf *ring, char *dest)
{
  uint	len;

  if ((len = seek_endline(ring)) == 0)
    {
      move_to_next_non_endline(ring);
      if (ring->len == RING_BUF_SIZE)
	ring_buf_ctor(ring);
      return (0);
    }
  else
    transfer_data(ring, dest, len);
  return (len);
}

int	ring_buf_pop_alloc(t_ring_buf *ring, char **dest)
{
  uint	len;

  if ((len = seek_endline(ring)) == 0)
    {
      move_to_next_non_endline(ring);
      if (ring->len == RING_BUF_SIZE)
	ring_buf_ctor(ring);
      return (0);
    }
  if ((*dest = malloc((len + 1) * sizeof(char))) == NULL)
    {
      print_perror("failed to allocate new string");
      return (-1);
    }
  else
    transfer_data(ring, *dest, len);
  return (len);
}
