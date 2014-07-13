/*
** ring_buf_ctor.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Network/src/ring_buffer
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:36:51 2014 Valentin
** Last update Sun Jul 13 19:36:57 2014 Valentin
*/

#include <stdlib.h>
#include <string.h>

#include "ring_buf.h"

void	ring_buf_ctor(t_ring_buf *ring)
{
  ring->head = 0;
  ring->tail = 0;
  ring->len = 0;
}
