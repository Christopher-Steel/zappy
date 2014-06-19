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
