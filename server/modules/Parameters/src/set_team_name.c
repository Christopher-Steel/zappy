/*
** set_team_name.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Parameters/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 18:57:15 2014 Valentin
** Last update Sun Jul 13 18:57:15 2014 Valentin
*/

#define	 _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "print_error.h"
#include "print_warning.h"
#include "set_parameter.h"

void	set_n(int ac, char **av)
{
  char	*tmp;

  if (optind >= ac || strncmp(av[optind], "-", 1) == 0)
    printf_warning("Missing argument for -n option. Using '%s' (default value)",
		   DEFAULT_N);
  else
    while (optind < ac && strncmp(av[optind], "-", 1) != 0)
      {
	if (g_server.param.team_names
	    && !strstr(g_server.param.team_names, av[optind]))
	  {
	    if (asprintf(&tmp, "%s%s\n", g_server.param.team_names,
			 av[optind]) == -1)
	      {
		print_error("failed to allocate team names string");
		return ;
	      }
	    free(g_server.param.team_names);
	    g_server.param.team_names = tmp;
	  }
	else if (!g_server.param.team_names)
	  asprintf(&g_server.param.team_names, "%s\n", av[optind]);
	++optind;
      }
}
