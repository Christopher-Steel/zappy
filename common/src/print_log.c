/*
** print_log.c for Common in /home/mougen_v/rendus/PSU_2013_zappy/common/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 17:59:26 2014 Valentin
** Last update Sun Jul 13 17:59:41 2014 Valentin
*/

#include <stdarg.h>
#include <stdio.h>

#include "print_log.h"

void	print_log(char *log)
{
  printf("%s", LOG_TAG);
  printf("%s\n", log);
}

void		printf_log(char *format, ...)
{
  va_list	vargs;

  printf("%s", LOG_TAG);
  va_start(vargs, format);
  vprintf(format, vargs);
  va_end(vargs);
  printf("\n");
}

void		printf_log_i(bool tag, char *format, ...)
{
  va_list	vargs;

  if (tag)
    printf("%s", LOG_TAG);
  va_start(vargs, format);
  vprintf(format, vargs);
  va_end(vargs);
}
