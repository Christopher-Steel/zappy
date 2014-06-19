#ifndef		PRINT_DEBUG_H_
# define	PRINT_DEBUG_H_

# define	DEBUG_TAG	"\033[1;34m[Debug]    \033[m"

void		print_debug(char *debug);
void		printf_debug(char *format, ...)
  __attribute__ ((format(printf, 1, 2)));

#endif		/* PRINT_DEBUG_H_ */
