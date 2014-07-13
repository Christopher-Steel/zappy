/*
** print_error.c for Common in /home/mougen_v/rendus/PSU_2013_zappy/common/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 17:57:44 2014 Valentin
** Last update Sun Jul 13 17:58:06 2014 Valentin
*/

#include <stdarg.h>
#include <stdio.h>

#include "print_error.h"
#include "zappy_types.h"

bool	print_error(char *err)
{
  fprintf(stderr, "%s", ERROR_TAG);
  fprintf(stderr, "%s\n", err);
  return (false);
}

bool	print_perror(char *err)
{
  fprintf(stderr, "%s", ERROR_TAG);
  perror(err);
  return (false);
}

bool		printf_error(char *format, ...)
{
  va_list	vargs;

  fprintf(stderr, "%s", ERROR_TAG);
  va_start(vargs, format);
  vfprintf(stderr, format, vargs);
  va_end(vargs);
  fprintf(stderr, "\n");
  return (false);
}

bool		printf_error_i(bool tag, char *format, ...)
{
  va_list	vargs;

  if (tag)
    fprintf(stderr, "%s", ERROR_TAG);
  va_start(vargs, format);
  vfprintf(stderr, format, vargs);
  va_end(vargs);
  return (false);
}
