/*
** print_log.h for Common in /home/mougen_v/rendus/PSU_2013_zappy/common/inc
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 17:55:30 2014 Valentin
** Last update Sun Jul 13 17:55:31 2014 Valentin
*/

#ifndef		PRINT_LOG_H_
# define	PRINT_LOG_H_

# define	LOG_TAG	"\033[1;32m[Log]      \033[m"

# include	"zappy_types.h"

void		print_log(char *log);

void		printf_log(char *format, ...)
  __attribute__ ((format(printf, 1, 2)));
void		printf_log_i(bool tag, char *format, ...)
  __attribute__ ((format(printf, 2, 3)));

#endif		/* PRINT_LOG_H_ */
