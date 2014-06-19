#include <stdarg.h>
#include <stdio.h>

#include "print_debug.h"

void		print_debug(char *debug)
{
  fprintf(stderr, "%s", DEBUG_TAG);
  fprintf(stderr, "%s\n", debug);
}

void		printf_debug(char *format, ...)
{
  va_list	vargs;

  fprintf(stderr, "%s", DEBUG_TAG);
  va_start(vargs, format);
  vfprintf(stderr, format, vargs);
  va_end(vargs);
  fprintf(stderr, "\n");
}
