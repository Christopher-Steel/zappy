#include <stdarg.h>
#include <stdio.h>

#include "print_warning.h"

void		print_warning(char *warning)
{
  fprintf(stderr, "%s", WARNING_TAG);
  fprintf(stderr, "%s\n", warning);
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
