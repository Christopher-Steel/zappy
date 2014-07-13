/*
** parse_parameter.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Parameters/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 18:57:59 2014 Valentin
** Last update Sun Jul 13 18:58:00 2014 Valentin
*/

#include <stdlib.h>

#include "parse_parameter.h"
#include "print_usage.h"
#include "set_parameter.h"

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
}
