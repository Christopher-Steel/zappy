/*
** print_error.h for Common in /home/mougen_v/rendus/PSU_2013_zappy/common/inc
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 17:53:58 2014 Valentin
** Last update Sun Jul 13 17:54:29 2014 Valentin
*/

#ifndef		PRINT_ERROR_H_
# define	PRINT_ERROR_H_

# define	ERROR_TAG	"\033[1;31m[Error]    \033[m"

# include	"zappy_types.h"

bool		print_error(char *err);
bool		print_perror(char *err);

bool		printf_error(char *format, ...)
  __attribute__ ((format(printf, 1, 2)));
bool		printf_error_i(bool tag, char *format, ...)
  __attribute__ ((format(printf, 2, 3)));

#endif		/* PRINT_ERROR_H_ */
