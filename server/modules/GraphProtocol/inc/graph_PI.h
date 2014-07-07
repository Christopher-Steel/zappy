
#ifndef		GRAPH_PI_H_
# define	GRAPH_PI_H_

#include	"zappy_types.h"
#include	"player.h"

#define	GRAPH_CMD(NAME, HAS_ARG) {#NAME, graphic_ ## NAME, HAS_ARG}

/* TODO remove this*/
bool	graphic_msz(t_player*, char*);
bool	graphic_bct(t_player*, char*);
bool	graphic_mct(t_player*, char*);
bool	graphic_tna(t_player*, char*);
bool	graphic_ppo(t_player*, char*);
bool	graphic_plv(t_player*, char*);
bool	graphic_pin(t_player*, char*);
bool	graphic_sgt(t_player*, char*);
bool	graphic_sst(t_player*, char*);
/* END of temporary */

typedef struct	s_graph_cmd
{
  char		*name;
  bool		(*fn)(t_player *, char *);
  bool		hasArg;
}		t_graph_cmd;

bool		graph_PI(t_player *player, char *cmd);
bool		graph_send_to(t_player, char *cmd);

#endif		/* !GRAPH_PI_H_ */
