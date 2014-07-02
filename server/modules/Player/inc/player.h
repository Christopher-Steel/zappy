#ifndef		PLAYER_H_
# define	PLAYER_H_

/*
** INCLUDES
*/
# include	<stdlib.h>
# include	<stdio.h>
# include	<stdbool.h>

# include	"vector.h"
# include	"list.h"
# include	"team.h"
# include	"server.h"

/*
** TYPEDEF
*/

typedef int	t_sock;
typedef struct s_team	t_team;

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

typedef struct	s_orientation
{
  enum e_ori	orientation;
  t_vector	vec;
}		t_orientation;

typedef struct	s_player
{
  unsigned int	inventory[7];
  unsigned int	level;
  t_vector	pos;
  t_orientation	orientation;
  int		socket;
  int		id;
  t_team	*team;
}		t_player;

/*
** FUNCTIONS
*/
t_player	*create_player(const t_vector pos, const enum e_ori ori,
			       const t_sock socket);
bool		set_orientation(t_player *player, const enum e_ori ori);
void		show_list_player(t_list *list);
bool		move_right(t_player *player, char *cmd);
bool		move_left(t_player *player, char *cmd);
bool		take_object(t_player *player, char *res);
bool		put_down_object(t_player *player, char *res);
bool		show_inventory(t_player *player, char *res);
bool		move_forward(t_player *player, char *cmd);
char		*convert_nbr_to_str(int nbr);
bool		look(t_player *player, char *cmd);
bool		send_view(int len, int *tab_view);

#endif		/* !PLAYER_H_ */
