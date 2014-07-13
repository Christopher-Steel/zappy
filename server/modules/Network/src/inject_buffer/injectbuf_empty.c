/*
** injectbuf_empty.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Network/src/inject_buffer
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:35:17 2014 Valentin
** Last update Sun Jul 13 19:35:18 2014 Valentin
*/

#include "inject_buffer.h"
#include "print_debug.h"

bool	injectbuf_empty(t_injectbuf *buf)
{
  return ((buf->len > 0 ? false : true));
}
