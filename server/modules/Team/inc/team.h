
#ifndef		TEAM_H_
# define	TEAM_H_

#include	"zappy_types.h"
#include	"player.h"
#include	"egg.h"
#include	"list.h"

typedef struct	s_client	t_client;

typedef struct	s_team
{
  int		id;
  char		*name;
  t_list	*members;
  uint		max_level;
  t_list	*eggs;
  uint		free_slots;
}		t_team;

t_team		*team_create(int id, char *name);
void		team_destroy(t_team *team);

void		team_update_max_level(t_team *team);

bool		team_add_player(t_player *player, char *team_name);
void		team_add_egg(t_egg *egg, char *team_name);

t_player	*team_create_player(char *team_name, t_client *client);

#endif		/* !TEAM_H_ */
