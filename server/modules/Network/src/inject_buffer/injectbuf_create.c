/*
** injectbuf_create.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Network/src/inject_buffer
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:35:08 2014 Valentin
** Last update Sun Jul 13 19:35:08 2014 Valentin
*/

#include <stdlib.h>

#include "inject_buffer.h"
#include "print_error.h"

t_injectbuf	*injectbuf_create(char *data, uint len)
{
  t_injectbuf	*newbuf;

  if ((newbuf = malloc(sizeof(*newbuf))) == NULL)
    {
      print_perror("failed to allocate new buffer");
      return (NULL);
    }
  newbuf->data = data;
  newbuf->head = 0;
  newbuf->len = len;
  return (newbuf);
}
