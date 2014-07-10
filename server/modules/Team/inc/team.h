
#ifndef		TEAM_H_
# define	TEAM_H_

#include	"egg.h"
#include	"list.h"
#include	"network_client.h"
#include	"player.h"
#include	"zappy_types.h"

typedef struct	s_player	t_player;
typedef struct	s_egg		t_egg;

typedef struct	s_team
{
  int		id;
  char		*name;
  t_list	*members;
  uint		max_level;
  t_list	*eggs;
  uint		free_slots;
}		t_team;

void		team_list_init(void);
void		team_list_destroy(void);

t_team		*team_create(int id, char *name);
void		team_destroy(t_team *team);

void		team_update_max_level(t_team *team);

bool		team_add_player(t_player *player, char *team_name);
void		team_add_egg(t_egg *egg, char *team_name);

void		team_remove_player(t_player* player);
void		team_remove_egg(t_egg *egg, bool hatch);

t_player	*team_create_player(char *team_name, t_client *client);

#endif		/* !TEAM_H_ */
