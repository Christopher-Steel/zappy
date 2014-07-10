
#ifndef		EGG_H_
# define	EGG_H_

# include	"team.h"
# include	"vector.h"
# include	"zappy_types.h"

typedef struct	s_team t_team;

typedef struct	s_egg
{
  int		id;
  t_team	*team;
  t_vector	pos;
}		t_egg;

t_egg	*egg_create(int id, t_team* team);
void	egg_destroy(t_egg *egg);

bool	egg_hatch(void *egg, void *unused);

#endif		/* !EGG_H_ */
