
#include <stdlib.h>

#include "print_error.h"
#include "print_warning.h"
#include "parse_parameter.h"
#include "set_parameter.h"
#include "print_usage.h"
#include "world.h"
#include "list.h"
#include "team.h"

static const char		*options = "pxyncth";

static const func_opt_ptr	set_opt[] =
{&set_p,
 &set_x,
 &set_y,
 &set_n,
 &set_c,
 &set_t,
 &print_usage,
 NULL};

void	set_default_param(void)
{
  g_server.info.port = DEFAULT_P;
  g_server.info.tick_delay = DEFAULT_T;
  g_server.param.team_max_id = 0;
  g_server.param.slots = DEFAULT_C;
  g_server.param.width = DEFAULT_X;
  g_server.param.height = DEFAULT_Y;
}

void	create_teams()
{
  char	*name;

  g_server.team_list = list_create();
  name = strtok(g_server.param.team_names, "\n");
  while (name)
    {
      team_create(++g_server.param.team_max_id, name);
      name = strtok(NULL, "\n");
    }
  free(g_server.param.team_names);
  if (g_server.team_list->size < 1)
    team_create(++g_server.param.team_max_id, "default_team");
}

void	parse_param(int ac, char **av)
{
  int	i;
  char	opt;

  set_default_param();
  while ((opt = getopt(ac, av, options)) != -1)
    {
      i = -1;
      while (++i < 7 && options[i] != opt);
      if (i < 7)
	set_opt[i](ac, av);
    }
  generate_world(g_server.param.height, g_server.param.width);
  create_teams();
}
