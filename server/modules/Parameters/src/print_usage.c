/*
** print_usage.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Parameters/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 18:58:22 2014 Valentin
** Last update Sun Jul 13 18:58:23 2014 Valentin
*/

#include <stdlib.h>
#include <stdio.h>

#include "print_usage.h"

void	print_usage(__attribute__ ((unused))int ac,
		    __attribute__ ((unused))char **av)
{
  printf("%s", USAGE_TAG);
  printf("%s%s%s\n", "./server [-OPTIONS ARGUMENT(s)]\n\t-p port\n\t-x width\n",
	 "\t-y height\n\t-n team_name1 team_name2 ...\n",
	 "\t-c slots_by_team (at the begining)\n\t-t tick_duration\n");
  exit(0);
}
