#ifndef		PLAYER_H_
# define	PLAYER_H_

/*
** INCLUDES
*/
# include	<stdlib.h>
# include	<stdio.h>

# include	"list.h"
# include	"network_client.h"
# include	"receiver.h"
# include	"team.h"
# include	"vector.h"
# include	"zappy_types.h"

/*
** TYPEDEF
*/

typedef struct s_egg	t_egg;
typedef struct s_event	t_event;
typedef struct s_team	t_team;

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
  void		(*event_handler)(t_event *event);
  unsigned int	inventory[7];
  unsigned int	level;
  t_vector	pos;
  enum e_ori	ori;
  int		id;
  long double	alive;
  void		*current_event;
  t_team	*team;
  t_client	*client;
}		t_player;

typedef struct		s_elevation
{
  unsigned int		res[7];
  int			nb_player;
  unsigned int		lvl_min;
}			t_elevation;

typedef struct	s_broadcast
{
  t_vector	pos_player[4];
  t_vector	pos_dest[4];
  t_player	*dest;
  int		dist[4];
}		t_broadcast;

typedef bool		(*t_pl_func)(void *, void *);

/*
** FUNCTIONS
*/
bool		player_avance(void *pl, void *unused);
bool		player_droite(void *pl, void *unused);
bool		player_gauche(void *pl, void *unused);
bool		player_voir(void *pl, void *unused);
bool		player_inventaire(void *pl, void *unused);
bool		player_prend(void *pl, void *res);
bool		player_pose(void *pl, void *res);
bool		player_expulse(void *pl, void *unused);
bool		player_broadcast(void *pl, void *msg);
bool		player_incantation(void *pl, void *cmd);
bool		player_fork(void *pl, void *cmd);
bool		player_connect_nbr(void *pl, void *unused);

bool		stop_elevation(void *pl, void *unused);
void		player_register_event(t_player *player);
void		player_event_handler(t_event *event);
void		resource_spreading(unsigned int pos, int cond);
bool		check_condition(t_player *player, t_node *node,
			        unsigned int pos);
bool		send_view(char *str, int *tab_view, t_player *player);
int		size_str_view(int *tab_view);
int		cnt_same_lvl(t_node *node, uint lvl);
t_player	*create_player(t_vector pos, enum e_ori ori,
			       t_client *client, t_team *team);
t_vector	get_vec_direction(enum e_ori ori);
int		calc_k(double angle);
double		calc_angle(t_vector pos_player,
			   t_vector pos_dest, t_player *dest);

void		player_life_update(void);

#endif		/* !PLAYER_H_ */
