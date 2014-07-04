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
# include	"server.h"
# include	"team.h"
# include	"vector.h"
# include	"zappy_types.h"
# include	"egg.h"

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

typedef struct	s_orientation
{
  enum e_ori	orientation;
  t_vector	vec;
}		t_orientation;

typedef struct	s_player
{
  void		(*receive)(t_receiver *rec, char *msg);
  void		(*destroy)(t_receiver *rec);
  unsigned int	inventory[7];
  unsigned int	level;
  t_vector	pos;
  t_orientation	orientation;
  int		id;
  t_team	*team;
  t_client	*client;
}		t_player;

/*
** FUNCTIONS
*/
void		show_list_player(t_list *list);
bool		set_orientation(t_player *player, const enum e_ori ori);
bool		move_right(t_player *player, char *cmd);
bool		move_left(t_player *player, char *cmd);
bool		take_object(t_player *player, char *res);
bool		put_down_object(t_player *player, char *res);
bool		show_inventory(t_player *player, char *res);
bool		move_forward(t_player *player, char *cmd);
bool		look(t_player *player, char *cmd);
bool		send_view(char *str, int *tab_view, t_player *player);
bool		lay(t_player *player, char *cmd);
char		*convert_nbr_to_str(int nbr);
int		size_str_view(int *tab_view);
t_player	*create_player(t_vector pos, enum e_ori ori, t_client *client);

#endif		/* !PLAYER_H_ */
