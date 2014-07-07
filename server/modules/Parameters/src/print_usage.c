
#include <stdio.h>

#include "print_usage.h"

void	print_usage(__attribute__ ((unused))int ac,
		    __attribute__ ((unused))char **av)
{
  printf("%s", USAGE_TAG);
  printf("%s%s%s\n", "./server [-OPTIONS ARGUMENT(s)]\n\t-p port\n\t-x width\n",
	 "\t-y height\n\t-n team_name1 team_name2 ...\n",
	 "\t-c slots_by_team (at the begining)\n\t-t tick_duration\n");
}
