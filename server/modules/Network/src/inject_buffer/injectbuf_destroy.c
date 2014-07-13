/*
** injectbuf_destroy.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Network/src/inject_buffer
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:34:52 2014 Valentin
** Last update Sun Jul 13 19:34:53 2014 Valentin
*/

#include <stdlib.h>

#include "inject_buffer.h"

void	injectbuf_destroy(t_injectbuf *buf, bool data)
{
  if (data)
    free(buf->data);
  free(buf);
}
