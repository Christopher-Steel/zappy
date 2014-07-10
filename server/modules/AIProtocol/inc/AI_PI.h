#ifndef		AI_PI_H_
# define	AI_PI_H_

# include	"player.h"
# include	"zappy_types.h"

#define		AI_CMD(NAME, ARG, T)	{#NAME, player_ ## NAME, ARG, T}

typedef struct	s_AI_cmd
{
  char		*name;
  bool		(*fn)(void *, void *);
  bool		hasArg;
  double	delay;
}		t_AI_cmd;

t_pl_func	AI_PI(char **cmd, double *delay);

#endif		/* AI_PI_H_ */
