/*
** printf_debug.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/common/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:52:11 2014 Valentin
** Last update Sun Jul 13 19:53:47 2014 Valentin
*/

#include <stdarg.h>
#include <stdio.h>

#include "print_debug.h"

#ifdef		DEBUG

void		printf_debug(char *format, ...)
{
  va_list	vargs;

  fprintf(stderr, "%s", DEBUG_TAG);
  va_start(vargs, format);
  vfprintf(stderr, format, vargs);
  va_end(vargs);
  fprintf(stderr, "\n");
}

void		printf_debug_i(bool tag, char *format, ...)
{
  va_list	vargs;

  if (tag)
    fprintf(stderr, "%s", DEBUG_TAG);
  va_start(vargs, format);
  vfprintf(stderr, format, vargs);
  va_end(vargs);
}

#else

void	printf_debug(char *format, ...)
{
  (void)format;
}

void	printf_debug_i(bool tag, char *format, ...)
{
  (void)tag;
  (void)format;
}

#endif
