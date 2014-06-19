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

bool	printf_error(char *format, ...)
{
  va_list	vargs;

  fprintf(stderr, "%s", ERROR_TAG);
  va_start(vargs, format);
  vfprintf(stderr, format, vargs);
  va_end(vargs);
  fprintf(stderr, "\n");
  return (false);
}

bool	printf_error_i(bool tag, char *format, ...)
{
  va_list	vargs;

  if (tag)
    fprintf(stderr, "%s", ERROR_TAG);
  va_start(vargs, format);
  vfprintf(stderr, format, vargs);
  va_end(vargs);
  return (false);
}
