
#include <stdlib.h>
#include <string.h>

#include "print_warning.h"
#include "set_parameter.h"

void	set_p(int ac, char **av)
{
  if (optind >= ac || strncmp(av[optind], "-", 1) == 0)
    printf_warning("Missing argument for -p option. Using %d (default value)",
		  DEFAULT_P);
  else if ((g_server.info.port = atoi(av[optind])) <= 0)
    {
      printf_warning("Invalid argument for -p option. Using %d (default value)",
		    DEFAULT_P);
      g_server.info.port = DEFAULT_P;
    }
}

void	set_x(int ac, char **av)
{
  if (optind >= ac || strncmp(av[optind], "-", 1) == 0)
    printf_warning("Missing argument for -x option. Using %d (default value)",
		  DEFAULT_X);
  else if ((g_server.param.width = atoi(av[optind])) <= 0)
    {
      printf_warning("Invalid argument for -x option. Using %d (default value)",
		    DEFAULT_X);
      g_server.param.width = DEFAULT_X;
    }
}

void	set_y(int ac, char **av)
{
  if (optind >= ac || strncmp(av[optind], "-", 1) == 0)
    printf_warning("Missing argument for -y option. Using %d (default value)",
		  DEFAULT_Y);
  else if ((g_server.param.height = atoi(av[optind])) <= 0)
    {
      printf_warning("Invalid argument for -y option. Using %d (default value)",
		    DEFAULT_Y);
      g_server.param.height = DEFAULT_Y;
    }
}

void	set_c(int ac, char **av)
{
  if (optind >= ac || strncmp(av[optind], "-", 1) == 0)
    printf_warning("Missing argument for -c option. Using %d (default value)",
		  DEFAULT_C);
  else if ((g_server.param.slots = atoi(av[optind])) <= 0)
    {
      printf_warning("Invalid argument for -c option. Using %d (default value)",
		    DEFAULT_C);
      g_server.param.slots = DEFAULT_C;
    }
}

void	set_t(int ac, char **av)
{
  if (optind >= ac || strncmp(av[optind], "-", 1) == 0)
    printf_warning("Missing argument for -t option. Using %d (default value)",
		  DEFAULT_T);
  else if ((g_server.info.tick_delay = atoi(av[optind])) <= 0)
    {
      printf_warning("Invalid argument for -t option. Using %d (default value)",
		    DEFAULT_T);
      g_server.info.tick_delay = DEFAULT_T;
    }
}
