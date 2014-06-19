#ifndef		PRINT_LOG_H_
# define	PRINT_LOG_H_

# define	LOG_TAG	"\033[1;32m[Log]      \033[m"

void		print_log(char *log);
void		printf_log(char *format, ...)
  __attribute__ ((format(printf, 1, 2)));

#endif		/* PRINT_LOG_H_ */
