/*
** ring_buf_empty.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Network/src/ring_buffer
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:36:31 2014 Valentin
** Last update Sun Jul 13 19:36:31 2014 Valentin
*/

#include "ring_buf.h"

bool	ring_buf_empty(t_ring_buf *ring)
{
  return ((ring->len == 0));
}
