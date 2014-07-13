/*
** world.h for zappy in /home/launoi_a/tmp/PSU_2013_zappy/server/modules/World
** 
** Made by allyriane.launois
** Login   <launoi_a@epitech.net>
** 
** Started on  Sun Jul 13 19:14:14 2014 allyriane.launois
** Last update Sun Jul 13 23:22:58 2014 frederic tan
*/

#ifndef		WORLD_H_
# define	WORLD_H_

# include	<stdlib.h>
# include	<stdio.h>
# include	<stdbool.h>
# include	<string.h>

# include	"egg.h"
# include	"player.h"
# include	"team.h"
# include	"vector.h"

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
typedef struct	s_team		t_team;
typedef struct	s_player	t_player;
typedef struct	s_egg		t_egg;

typedef struct	s_cell
{
  unsigned int	res[7];
  t_list	list_egg;
  t_list	list_player;
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
void		remove_player(const int id, const int position);
void		delete_player(t_player *player);
void		get_vision_point(int *tab, t_player *player);
void		respawn_resource(unsigned int *res);
bool		generate_world(const unsigned int height,
			       const unsigned int width);
bool		add_player(t_player *player, const int pos);
bool		victory_condition_resolve(void);
bool		add_egg(t_egg *egg, const int pos);
t_vector	wrap_horizontal(t_vector vec);
t_vector	wrap_vertical(t_vector vec);
t_player	*spawn_player(t_client *client, t_team *team);
t_player	*spawn_pos_player(t_client *client, t_team *team, t_egg *egg);

#endif		/* !WORLD_H_ */
