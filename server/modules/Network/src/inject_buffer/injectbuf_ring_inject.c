/*
** injectbuf_ring_inject.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Network/src/inject_buffer
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:34:35 2014 Valentin
** Last update Sun Jul 13 19:34:45 2014 Valentin
*/

#include "inject_buffer.h"

bool	injectbuf_ring_inject(t_injectbuf *buf, t_ring_buf *ring)
{
  int	len;

  len = ring_buf_push(ring, &buf->data[buf->head]);
  buf->len -= len;
  buf->head += len;
  return (injectbuf_empty(buf));
}
