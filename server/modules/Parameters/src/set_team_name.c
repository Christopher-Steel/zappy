
#define	 _GNU_SOURCE
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "print_warning.h"
#include "set_parameter.h"

void	set_n(int ac, char **av)
{
  char	*tmp;

  if (optind >= ac || strncmp(av[optind], "-", 1) == 0)
    print_warning("Missing argument for -n option. Using default value.\n");
  else
    {
      while (optind < ac && strncmp(av[optind], "-", 1) != 0)
	{
	  if (g_param.team_names && !strstr(g_param.team_names, av[optind]))
	    {
	      asprintf(&tmp, "%s%s\n", g_param.team_names,av[optind]);
	      free(g_param.team_names);
	      g_param.team_names = tmp;
	    }
	  else if (!g_param.team_names)
	    asprintf(&g_param.team_names, "%s\n", av[optind]);
	  ++optind;
	}
    }
}
