/*
** print_warning.c for Common in /home/mougen_v/rendus/PSU_2013_zappy/common/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 17:56:12 2014 Valentin
** Last update Sun Jul 13 17:56:36 2014 Valentin
*/

#include <stdarg.h>
#include <stdio.h>

#include "print_warning.h"

void	print_warning(char *warning)
{
  fprintf(stderr, "%s", WARNING_TAG);
  fprintf(stderr, "%s\n", warning);
}

void	print_pwarning(char *warning)
{
  fprintf(stderr, "%s", WARNING_TAG);
  perror(warning);
}

void		printf_warning(char *format, ...)
{
  va_list	vargs;

  fprintf(stderr, "%s", WARNING_TAG);
  va_start(vargs, format);
  vfprintf(stderr, format, vargs);
  va_end(vargs);
  fprintf(stderr, "\n");
}

void		printf_warning_i(bool tag, char *format, ...)
{
  va_list	vargs;

  if (tag)
    fprintf(stderr, "%s", WARNING_TAG);
  va_start(vargs, format);
  vfprintf(stderr, format, vargs);
  va_end(vargs);
}
