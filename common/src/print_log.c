#include <stdarg.h>
#include <stdio.h>

#include "print_log.h"

void		print_log(char *log)
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
