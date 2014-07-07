#ifndef		AI_PI_H_
# define	AI_PI_H_

# include	"zappy_types.h"

/* TODO remove this */
typedef int	t_player;
bool		player_voir(t_player *, char *);
bool		player_avance(t_player *, char *);
bool		player_droite(t_player *, char *);
bool		player_gauche(t_player *, char *);
bool		player_prend(t_player *, char *);
bool		player_pose(t_player *, char *);
bool		player_expulse(t_player *, char *);
bool		player_broadcast(t_player *, char *);
bool		player_incantation(t_player *, char *);
bool		player_fork(t_player *, char *);
bool		player_connect_nbr(t_player *, char *);
bool		player_inventaire(t_player *, char *);
/* END of temporary*/

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
