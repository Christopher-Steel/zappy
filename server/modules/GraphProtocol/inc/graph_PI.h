
#ifndef		GRAPH_PI_H_
# define	GRAPH_PI_H_

# include	"graphic.h"
# include	"zappy_types.h"

# define	GRAPH_CMD(NAME, HAS_ARG) {#NAME, graphic_ ## NAME, HAS_ARG}

typedef struct	s_graph_cmd
{
  char		*name;
  bool		(*fn)(t_graphic *, char *);
  bool		hasArg;
}		t_graph_cmd;

bool		graph_PI(t_graphic *graphic, char *cmd);
bool		graph_send_to(t_graphic *graphic, char *cmd);

#endif		/* !GRAPH_PI_H_ */
