#include <stdarg.h>
#include <stdio.h>

#include "print_log.h"

void		print_log(char *log)
{
  fprintf(stderr, "%s", LOG_TAG);
  fprintf(stderr, "%s\n", log);
}

void		printf_log(char *format, ...)
{
  va_list	vargs;

  fprintf(stderr, "%s", LOG_TAG);
  va_start(vargs, format);
  vfprintf(stderr, format, vargs);
  va_end(vargs);
  fprintf(stderr, "\n");
}

void		printf_log_i(bool tag, char *format, ...)
{
  va_list	vargs;

  if (tag)
    fprintf(stderr, "%s", LOG_TAG);
  va_start(vargs, format);
  vfprintf(stderr, format, vargs);
  va_end(vargs);
}
