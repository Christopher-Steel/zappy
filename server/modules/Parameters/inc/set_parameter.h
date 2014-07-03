
#ifndef		SET_PARAMETER_H_
# define	SET_PARAMETER_H_

# include	<unistd.h>

# include	"server.h"

# define	OPTION_TAGS	"pxyncth"

# define	DEFAULT_P	1337
# define	DEFAULT_X	10
# define	DEFAULT_Y	10
# define	DEFAULT_N	"trantorians"
# define	DEFAULT_C	1
# define	DEFAULT_T	100

void		set_p(int ac, char **av);
void		set_x(int ac, char **av);
void		set_y(int ac, char **av);
void		set_c(int ac, char **av);
void		set_t(int ac, char **av);
void		set_n(int ac, char **av);

//char		*get_next_team_name(t_team_param *team_param);
//int		get_next_id(t_team_param *team_param);

#endif		/* !SET_PARAMETER_H_ */
