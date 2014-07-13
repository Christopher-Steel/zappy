/*
** ring_buf_len.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Network/src/ring_buffer
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:37:07 2014 Valentin
** Last update Sun Jul 13 19:37:08 2014 Valentin
*/

#include "ring_buf.h"

unsigned int	ring_buf_len(t_ring_buf *ring)
{
  return (ring->len);
}
