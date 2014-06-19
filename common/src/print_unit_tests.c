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
  printf_error("Another error, this one has "
	       "var args :) %d %f", 17, 4.22222f);
  printf_error_i(true, "Another error, this one has "
		 "var args :) %d %f", 17, 4.22222f);
  printf_error_i(false, "Another error, this one has "
		 "var args :) %d %f\n", 17, 4.22222f);
  print_warning("I'll warn you once.");
  printf_warning("But only once. %d %f", 17, 4.22222f);
  printf_warning_i(true, "But only once. %d %f", 17, 4.22222f);
  printf_warning_i(false, "But only once. %d %f\n", 17, 4.22222f);
  print_log("Hey there, nice day, right ?");
  printf_log("The temperature is %d degrees celsius "
	    "with a %f km/h wind", 17, 4.22222f);
  printf_log_i(true, "The temperature is %d degrees celsius ", 17);
  printf_log_i(false, "with a %f km/h wind\n", 4.22222f);
  print_debug("str == \"tortoise\"");
  printf_debug("ac == %d, av == %p", ac, (void *)av);
  printf_debug_i(true, "ac == %d, ", ac);
  printf_debug_i(false, "av == %p\n", (void *)av);
  return (0);
}
