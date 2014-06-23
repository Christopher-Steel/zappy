#ifndef		SERVER_H_
# define	SERVER_H_

/*
** INCLUDE
*/
# include	"world.h"

/*
** STRUCTURE
*/

struct	s_world;

typedef struct		s_server
{
  struct s_world	*world;
}			t_server;

/*
** FUNCTION
*/
unsigned int	gs_get_map_width(void);
unsigned int	gs_get_map_height(void);
unsigned int	gs_get_map_size(void);

/*
** GLOBALE
*/
t_server	g_server;

#endif		/* !SERVER_H_ */
