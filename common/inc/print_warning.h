#ifndef		PRINT_WARNING_H_
# define	PRINT_WARNING_H_

# define	WARNING_TAG	"\033[1;33m[Warning]  \033[m"

void		print_warning(char *warning);
void		printf_warning(char *format, ...)
  __attribute__ ((format(printf, 1, 2)));

#endif		/* PRINT_WARNING_H_ */
