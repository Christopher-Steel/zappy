#include <stdarg.h>
#include <stdio.h>

#include "print_debug.h"

void		print_debug(char *debug)
{
#ifdef		DEBUG
  fprintf(stderr, "%s", DEBUG_TAG);
  fprintf(stderr, "%s\n", debug);
#else
  (void)debug;
#endif
}

void		printf_debug(char *format, ...)
{
#ifdef		DEBUG
  va_list	vargs;

  fprintf(stderr, "%s", DEBUG_TAG);
  va_start(vargs, format);
  vfprintf(stderr, format, vargs);
  va_end(vargs);
  fprintf(stderr, "\n");
#else
  (void)format;
#endif
}

void		printf_debug_i(bool tag, char *format, ...)
{
#ifdef		DEBUG
  va_list	vargs;

  if (tag)
    fprintf(stderr, "%s", DEBUG_TAG);
  va_start(vargs, format);
  vfprintf(stderr, format, vargs);
  va_end(vargs);
#else
  (void)tag;
  (void)format;
#endif
}
