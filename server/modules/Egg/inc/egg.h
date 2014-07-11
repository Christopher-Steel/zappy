
#ifndef		EGG_H_
# define	EGG_H_

# include	"event_handler.h"
# include	"team.h"
# include	"vector.h"
# include	"zappy_types.h"

typedef struct	s_team t_team;

typedef struct	s_egg
{
  void		(*padding[2])(void);
  void		(*event_handler)(t_event_handler *handler);
  int		id;
  t_team	*team;
  t_vector	pos;
}		t_egg;

t_egg	*egg_create(int id, t_team* team);
void	egg_destroy(t_egg *egg);

bool	egg_hatch(void *egg, void *unused);
void	egg_event_handler(t_event_handler *handler);

#endif		/* !EGG_H_ */
