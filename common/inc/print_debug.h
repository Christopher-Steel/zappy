/*
** print_debug.h for Common in /home/mougen_v/rendus/PSU_2013_zappy/common/inc
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 17:55:12 2014 Valentin
** Last update Sun Jul 13 17:55:14 2014 Valentin
*/

#ifndef		PRINT_DEBUG_H_
# define	PRINT_DEBUG_H_

# define	DEBUG_TAG	"\033[1;34m[Debug]    \033[m"

# include	"zappy_types.h"

void		print_debug(char *debug);

void		printf_debug(char *format, ...)
  __attribute__ ((format(printf, 1, 2)));
void		printf_debug_i(bool tag, char *format, ...)
  __attribute__ ((format(printf, 2, 3)));

#endif		/* PRINT_DEBUG_H_ */
