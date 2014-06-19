#include <fcntl.h>
#include <stdio.h>

#include "print_error.h"
#include "print_warning.h"
#include "print_debug.h"
#include "print_log.h"

int	main(int ac, char *av[])
{
  print_error("Woops, looks like there was an error !");
  open(".", O_RDONLY);
  print_perror("Huehue, trying to open . is fun.");
  printf_error("Another error, this one has var args :) %d %f", 17, 4.22222f);
  print_warning("I'll warn you once.");
  printf_warning("But only once. %d %f", 17, 4.22222f);
  print_log("Hey there, nice day, right ?");
  printf_log("The temperature is %d degrees celsius "
	    "with a %f km/h wind", 17, 4.22222f);
  print_debug("str == \"tortoise\"");
  printf_debug("ac == %d, av == %p", ac, (void *)av);
  return (0);
}
