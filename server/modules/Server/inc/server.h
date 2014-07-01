#ifndef		SERVER_H_
# define	SERVER_H_

/*
** INCLUDE
*/
# include	"list.h"
# include	"network.h"
# include	"world.h"

/*
** STRUCTURE
*/

struct			s_world;

typedef struct		s_param
{
  int			width;
  int			height;
  int			team_max_id;
  int			slots;
  char			*team_names;
}			t_param;

typedef struct		s_info
{
  int			tick_delay;
  int			port;
}			t_info;

typedef struct		s_server
{
  t_info		info;
  t_list		*team_list;
  t_param		param;
  t_network		network;
  struct s_world	*world;
}			t_server;

/*
** FUNCTION
*/
unsigned int	gs_get_map_width(void);
unsigned int	gs_get_map_height(void);
unsigned int	gs_get_map_size(void);

/*
** GLOBAL
*/
t_server	g_server;

#endif		/* !SERVER_H_ */
