#include <stdio.h>

#include "server.h"
#include "world.h"
#include "team.h"
#include "parse_parameter.h"
#include "set_parameter.h"

int	main(int ac, char **av)
{
  parse_param(ac, av);

  printf("end parsing parameters\n");
  return (0);
}
