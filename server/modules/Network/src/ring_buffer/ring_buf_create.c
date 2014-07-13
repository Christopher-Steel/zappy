/*
** ring_buf_create.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Network/src/ring_buffer
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:36:39 2014 Valentin
** Last update Sun Jul 13 19:36:39 2014 Valentin
*/

#include <stdlib.h>

#include "ring_buf.h"

t_ring_buf	*ring_buf_create(void)
{
  t_ring_buf	*new_ring;

  if ((new_ring = malloc(sizeof(*new_ring))) == NULL)
    return (NULL);
  ring_buf_ctor(new_ring);
  return (new_ring);
}
