#ifndef		PRINT_ERROR_H_
# define	PRINT_ERROR_H_

# define	ERROR_TAG	"\033[1;31m[Error]    \033[m"

# include	"zappy_types.h"

bool		print_error(char *err);
bool		print_perror(char *err);
bool		printf_error(char *format, ...)
  __attribute__ ((format(printf, 1, 2)));

#endif		/* PRINT_ERROR_H_ */
