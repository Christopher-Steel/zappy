/*
** graph_PI.h for zappy in /home/launoi_a/tmp/PSU_2013_zappy/server/modules/GraphProtocol
** 
** Made by allyriane.launois
** Login   <launoi_a@epitech.net>
** 
** Started on  Sun Jul 13 18:51:35 2014 allyriane.launois
** Last update Sun Jul 13 18:55:29 2014 allyriane.launois
*/

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

bool		graph_pose(void *player, void *obj)
  __attribute__ ((nonnull));
bool		graph_prend(void *player, void *obj)
  __attribute__ ((nonnull));

bool		graph_incantation(t_list *players)
  __attribute__ ((nonnull));
bool		graph_end_incantation(t_player *player, t_list *players, int result)
  __attribute__ ((nonnull));

#endif		/* !GRAPH_PI_H_ */
