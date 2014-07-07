#ifndef		AI_PI_H_
# define	AI_PI_H_

# include	"player.h"
# include	"zappy_types.h"

#define		AI_CMD(NAME, HAS_ARG)	{#NAME, player_ ## NAME, HAS_ARG}

typedef struct	s_AI_cmd
{
  char		*name;
  bool		(*fn)(t_player *, char *);
  bool		hasArg;
}		t_AI_cmd;

bool		AI_PI(t_player *, char *);
bool		AI_send_to(t_player, char *);

#endif		/* AI_PI_H_ */
