/*
** print_warning.h for Common in /home/mougen_v/rendus/PSU_2013_zappy/common/inc
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 17:51:47 2014 Valentin
** Last update Sun Jul 13 17:53:50 2014 Valentin
*/

#ifndef		PRINT_WARNING_H_
# define	PRINT_WARNING_H_

# define	WARNING_TAG	"\033[1;33m[Warning]  \033[m"

# include	"zappy_types.h"

void		print_warning(char *warning);
void		print_pwarning(char *warning);

void		printf_warning(char *format, ...)
  __attribute__ ((format(printf, 1, 2)));
void		printf_warning_i(bool tag, char *format, ...)
  __attribute__ ((format(printf, 2, 3)));

#endif		/* PRINT_WARNING_H_ */
