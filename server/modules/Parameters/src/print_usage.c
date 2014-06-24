
#include <stdio.h>

#include "print_usage.h"

void	print_usage(__attribute__((unused))int ac,
		    __attribute__((unused)) char **av)
{
  printf("%s", USAGE_TAG);
  printf("%s\n", USAGE_MSG);
  //exit(0);
}
