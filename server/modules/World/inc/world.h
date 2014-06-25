#ifndef		WORLD_H_
# define	WORLD_H_

# include	<stdlib.h>
# include	<stdio.h>
# include	<stdbool.h>
# include	<string.h>

# include	"server.h"
# include	"player.h"

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
typedef struct	s_cell
{
  unsigned int	res[7];
  t_list_player	*list_player;
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
bool		generate_world(const unsigned int height,
			       const unsigned int width);
void		spawn_ressource(t_world *world);
bool		spawn_player(const t_sock socket, const int id);
void		remove_player(const int id, const int position);
bool		add_player(t_player *player, const int pos);
unsigned int	listlen(t_list_player *list);

#endif		/* !WORLD_H_ */
