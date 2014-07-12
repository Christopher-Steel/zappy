
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


void		**mount_args(void *arg1, void *arg2)
  __attribute__ ((nonnull));
bool		graph_for_each(bool (*func)(t_graphic*))
  __attribute__ ((nonnull));
bool		graph_for_each_1_arg(bool (*func)(t_graphic*, void *),
				     void *arg)
  __attribute__ ((nonnull));
bool		graph_for_each_2_args(bool (*func)(t_graphic*, void *, void *),
				      void **args)
  __attribute__ ((nonnull));

#endif		/* !GRAPH_PI_H_ */
