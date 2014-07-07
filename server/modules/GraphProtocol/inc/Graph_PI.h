
#ifndef		GRAPH_PI_H_
# define	GRAPH_PI_H_

# include	"player.h"
# include	"zappy_types.h"

/* TODO remove this*/
bool		graphic_msz(t_graphic *, char *);
bool		graphic_bct(t_graphic *, char *);
bool		graphic_mct(t_graphic *, char *);
bool		graphic_tna(t_graphic *, char *);
bool		graphic_ppo(t_graphic *, char *);
bool		graphic_plv(t_graphic *, char *);
bool		graphic_pin(t_graphic *, char *);
bool		graphic_sgt(t_graphic *, char *);
bool		graphic_sst(t_graphic *, char *);
/* END of temporary */

# define	GRAPH_CMD(NAME, HAS_ARG) {#NAME, graphic_ ## NAME, HAS_ARG}

typedef struct	s_graph_cmd
{
  char		*name;
  bool		(*fn)(t_graphic *, char *);
  bool		hasArg;
}		t_graph_cmd;

bool		graph_PI(t_player *player, char *cmd);

#endif		/* !GRAPH_PI_H_ */
