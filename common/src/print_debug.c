/*
** print_debug.c for Common in /home/mougen_v/rendus/PSU_2013_zappy/common/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 17:58:36 2014 Valentin
** Last update Sun Jul 13 19:53:39 2014 Valentin
*/

#include <stdio.h>

#include "print_debug.h"

#ifdef		DEBUG

void	print_debug(char *debug)
{
  fprintf(stderr, "%s", DEBUG_TAG);
  fprintf(stderr, "%s\n", debug);
}

#else

void	print_debug(char *debug)
{
  (void)debug;
}

#endif
