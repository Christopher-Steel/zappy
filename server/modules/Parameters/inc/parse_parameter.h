
#ifndef		PARSE_PARAMETER_H_
# define	PARSE_PARAMETER_H_

# include	"server.h"

typedef void (*func_opt_ptr)(int ac, char **av);

void		parse_param(int ac, char **av);

#endif		/* !PARSE_PARAMETER_H_ */
