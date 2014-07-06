#ifndef		WORLD_H_
# define	WORLD_H_

# include	<stdlib.h>
# include	<stdio.h>
# include	<stdbool.h>
# include	<string.h>

# include	"egg.h"
# include	"player.h"
# include	"server.h"
# include	"team.h"
# include	"vector.h"
# include	"elevation.h"

/*
** DEFINE
*/

# define	RES_SPAWN 60
# define	NBR_SPAWN 10

/*
** ENUM
*/

enum	e_ressource
  {
    FOOD,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME
  };

/*
** STRUCTURE
*/
typedef struct	s_player	t_player;
typedef struct	s_egg		t_egg;

typedef struct	s_cell
{
  unsigned int	res[7];
  t_list	*list_egg;
  t_list	*list_player;
}		t_cell;

typedef struct	s_world
{
  unsigned int	size;
  unsigned int	height;
  unsigned int	width;
  t_cell	*cell;
}		t_world;

/*
** FONCTION
*/
void		spawn_ressource(t_world *world);
void		remove_player(const int id, const int position);
void		delete_player(t_player *player);
void		list_world(t_player *my_player);
void		get_vision_point(int *tab, t_player *player);
bool		generate_world(const unsigned int height,
			       const unsigned int width);
bool		add_player(t_player *player, const int pos);
bool		add_egg(t_egg *egg, const int pos);
bool		init_elevation_cond(void);
t_vector	wrap_horizontal(t_vector vec);
t_vector	wrap_vertical(t_vector vec);
t_player	*spawn_player(t_client *client);

#endif		/* !WORLD_H_ */
