#ifndef		PLAYER_H_
# define	PLAYER_H_

/*
** INCLUDES
*/
# include	<stdlib.h>
# include	<stdio.h>
# include	<stdbool.h>

# include	"vector.h"

/*
** TYPEDEF
*/
typedef int	t_sock;

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
}		t_player;

typedef struct	s_list_player
{
  t_player		*player;
  struct s_list_player	*next;
}		t_list_player;

/*
** FUNCTIONS
*/
t_player	*create_player(const t_vector pos, const enum e_ori ori,
			       const t_sock socket, const int id);
void		set_orientation(t_player *player, const enum e_ori ori);
void		show_list_player(t_list_player *list);
void		move_right(t_player *player, char *cmd);
void		move_left(t_player *player, char *cmd);
bool		take_object(t_player *player, char *res);
bool		put_down_object(t_player *player, char *res);
void		show_inventory(t_player *player, char *res);
void		move_forward(t_player *player, char *cmd);

#endif		/* !PLAYER_H_ */
