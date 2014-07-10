
#ifndef		SET_PARAMETER_H_
# define	SET_PARAMETER_H_

# include	<unistd.h>

# include	"server.h"

# define	OPTION_TAGS	"pxyncth"

# define	DEFAULT_P	4242
# define	DEFAULT_X	10
# define	DEFAULT_Y	10
# define	DEFAULT_N	"team1"
# define	DEFAULT_C	1
# define	DEFAULT_T	100

void		set_p(int ac, char **av);
void		set_x(int ac, char **av);
void		set_y(int ac, char **av);
void		set_c(int ac, char **av);
void		set_t(int ac, char **av);
void		set_n(int ac, char **av);

#endif		/* !SET_PARAMETER_H_ */
