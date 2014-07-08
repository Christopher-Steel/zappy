
#include <stdlib.h>

#include "list.h"
#include "parse_parameter.h"
#include "print_error.h"
#include "print_usage.h"
#include "print_warning.h"
#include "set_parameter.h"
#include "team.h"
#include "world.h"

static const func_opt_ptr	g_set_opt[] =
  {
    &set_p,
    &set_x,
    &set_y,
    &set_n,
    &set_c,
    &set_t,
    &print_usage,
    NULL
  };

static void	set_default_param(void)
{
  g_server.info.port = DEFAULT_P;
  g_server.info.tick_delay = DEFAULT_T;
  g_server.param.team_max_id = 0;
  g_server.param.slots = DEFAULT_C;
  g_server.param.width = DEFAULT_X;
  g_server.param.height = DEFAULT_Y;
}

static void	create_teams()
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
    {
      printf_warning("No team names specified, defaulting to \"%s\"",
		     DEFAULT_N);
      team_create(++g_server.param.team_max_id, DEFAULT_N);
    }
}

void	parse_param(int ac, char **av)
{
  int	i;
  char	opt;

  set_default_param();
  while ((opt = getopt(ac, av, OPTION_TAGS)) != -1)
    {
      i = -1;
      while (++i < 7 && OPTION_TAGS[i] != opt);
      if (i < 7)
	g_set_opt[i](ac, av);
    }
  generate_world(g_server.param.height, g_server.param.width);
  create_teams();
}
