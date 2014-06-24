
#ifndef		PRINT_USAGE_H_
# define	PRINT_USAGE_H_

# include	"server.h"

# define	USAGE_TAG	"\033[1;34m[Usage]	\033[m"
# define	USAGE_MSG	"./server [-OPTIONS ARGUMENT(s)]\n \
		-p port\n \
		-x width\n \
		-y height\n \
		-n team_name1 team_name2 ...\n \
		-c slots_by_team (at the begining)\n \
		-t tick_duration\n"

void		print_usage(int ac, char **av);

#endif		/* !PRINT_USAGE_H_ */
