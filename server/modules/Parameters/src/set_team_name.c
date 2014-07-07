
#define	 _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "print_warning.h"
#include "set_parameter.h"

void	set_n(int ac, char **av)
{
  char	*tmp;

  if (optind >= ac || strncmp(av[optind], "-", 1) == 0)
    printf_warning("Missing argument for -n option. Using '%s' (default value)",
		   DEFAULT_N);
  else
    {
      while (optind < ac && strncmp(av[optind], "-", 1) != 0)
	{
	  if (g_server.param.team_names
	      && !strstr(g_server.param.team_names, av[optind]))
	    {
	      asprintf(&tmp, "%s%s\n", g_server.param.team_names, av[optind]);
	      free(g_server.param.team_names);
	      g_server.param.team_names = tmp;
	    }
	  else if (!g_server.param.team_names)
	    asprintf(&g_server.param.team_names, "%s\n", av[optind]);
	  ++optind;
	}
    }
}
