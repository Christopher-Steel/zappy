#ifndef		PLAYER_H_
# define	PLAYER_H_

/*
** INCLUDES
*/
# include	<stdlib.h>
# include	<stdio.h>

# include	"egg.h"
# include	"list.h"
# include	"network_client.h"
# include	"receiver.h"
# include	"server.h"
# include	"team.h"
# include	"vector.h"
# include	"zappy_types.h"

/*
** TYPEDEF
*/

typedef struct	s_team		t_team;

/*
** DEFINES
*/

# define	MAX_CLIENT_OUTQ	10

/*
** ENUM
*/
enum	e_ori
  {
    NORTH,
    EAST,
    SOUTH,
    WEST
  };

/*
** STRUCTURES
*/

typedef struct	s_in_view
{
  bool		is_player;
  bool		is_res;
  bool		is_egg;
}		t_in_view;

typedef struct	s_vision
{
  t_vector	start;
  t_vector	end;
  t_vector	pos;
  int		dist;
}		t_vision;

typedef struct	s_player
{
  void		(*receive)(t_receiver *rec, char *msg);
  void		(*destroy)(t_receiver *rec);
  unsigned int	inventory[7];
  unsigned int	level;
  t_vector	pos;
  enum e_ori	ori;
  int		id;
  long double	alive;
  t_team	*team;
  t_client	*client;
}		t_player;

typedef struct		s_elevation
{
  unsigned int		res[7];
  int			nb_player;
  unsigned int		lvl_min;
}			t_elevation;

/*
** FUNCTIONS
*/
bool		player_avance(t_player *player, char *unused);
bool		player_droite(t_player *player, char *unused);
bool		player_gauche(t_player *player, char *unused);
bool		player_voir(t_player *player, char *unused);
bool		player_inventaire(t_player *player, char *unused);
bool		player_prend(t_player *player, char *res);
bool		player_pose(t_player *player, char *res);
bool		player_expulse(t_player *player, char *unused);
bool		player_broadcast(t_player *player, char *msg);
bool		player_incantation(t_player *player, char *cmd);
bool		player_fork(t_player *player, char *cmd);
bool		player_connect_nbr(t_player *player, char *unused);

void		show_list_player(t_list *list);
bool		send_view(char *str, int *tab_view, t_player *player);
bool		stop_elevation(t_player *player, char *unused);
char		*convert_nbr_to_str(int nbr);
int		size_str_view(int *tab_view);
t_player	*create_player(t_vector pos, enum e_ori ori,
			       t_client *client, t_team *team);
t_vector	get_vec_direction(enum e_ori ori);

void		player_life_update(void);

#endif		/* !PLAYER_H_ */
