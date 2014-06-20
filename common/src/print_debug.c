#include <stdarg.h>
#include <stdio.h>

#include "print_debug.h"

#ifdef		DEBUG

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

void		print_debug(char *debug)
{
  (void)debug;
}

void		printf_debug(char *format, ...)
{
  (void)format;
}

void		printf_debug_i(bool tag, char *format, ...)
{
  (void)tag;
  (void)format;
}

#endif
