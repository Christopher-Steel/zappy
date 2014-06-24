
#include <stdlib.h>

#include "print_error.h"
#include "print_warning.h"
#include "parse_parameter.h"
#include "set_parameter.h"
#include "print_usage.h"
#include "world.h"
#include "list.h"
#include "team.h"

void	init_tab(void (*set_opt[7])(int ac, char **av), char options[7])
{
  options[0] = 'p';
  options[1] = 'x';
  options[2] = 'y';
  options[3] = 'n';
  options[4] = 'c';
  options[5] = 't';
  options[6] = 'h';

  set_opt[0] = &set_p;
  set_opt[1] = &set_x;
  set_opt[2] = &set_y;
  set_opt[3] = &set_n;
  set_opt[4] = &set_c;
  set_opt[5] = &set_t;
  set_opt[6] = &print_usage;
}

void	set_default_param(void)
{
  g_server.info.port = DEFAULT_P;
  g_server.info.tick_delay = DEFAULT_T;
  g_param.team_max_id = 0;
  g_param.slots = DEFAULT_C;
  g_param.width = DEFAULT_X;
  g_param.height = DEFAULT_Y;
}

void	create_teams()
{
  char	*name;

  g_server.team_list = list_create();
  name = strtok(g_param.team_names, "\n");
  while (name)
    {
      team_create(++g_param.team_max_id, name);
      name = strtok(NULL, "\n");
    }
  free(g_param.team_names);
}

void	parse_param(int ac, char **av)
{
  int	i;
  void	(*set_opt[7])(int ac, char **av);
  char	options[7];
  char	opt;

  init_tab(set_opt, options);
  set_default_param();
  while ((opt = getopt(ac, av, "pxyncth")) != -1)
    {
      i = -1;
      while (++i < 7 && options[i] != opt);
      if (i < 7)
	set_opt[i](ac, av);
    }
  generate_world(g_param.height, g_param.width);
  create_teams();
}
