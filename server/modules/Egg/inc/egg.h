
#ifndef		EGG_H_
# define	EGG_H_

# include	"team.h"
# include	"vector.h"
# include	"player.h"
# include	"zappy_types.h"

typedef struct	s_player	t_player;
typedef struct	s_event		t_event;
typedef struct	s_team		t_team;

typedef struct	s_egg
{
  void		(*padding[2])(void);
  void		(*event_handler)(t_event *event);
  bool		is_hatches;
  int		id;
  t_player	*player_lay;
  t_team	*team;
  t_vector	pos;
}		t_egg;

t_egg	*egg_create(int id, t_team* team);
void	egg_destroy(t_egg *egg);

bool	egg_hatch(void *egg, void *unused);
void	egg_event_handler(t_event *event);

#endif		/* !EGG_H_ */
