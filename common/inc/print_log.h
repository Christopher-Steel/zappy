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
