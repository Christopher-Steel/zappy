
#ifndef		TEAM_H_
# define	TEAM_H_

#include	"zappy_types.h"
#include	"list.h"
#include	"player.h"

typedef struct	s_team
{
  int		id;
  char		*name;
  t_list	*members;
  int		max_level;
  t_list	*eggs;
  uint		free_slots;
}		t_team;

t_team		*team_create(int id, char *name);
void		team_destroy(t_team *team);

void		team_update_max_level(t_team *team);

void		team_add_player(t_player *, char *team_name);

#endif		/* !TEAM_H_ */
