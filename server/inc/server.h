#ifndef		SERVER_H_
# define	SERVER_H_

/*
** INCLUDE
*/
# include	"event.h"
# include	"graphic.h"
# include	"list.h"
# include	"network.h"
# include	"world.h"

/*
** STRUCTURE
*/

typedef struct	s_world			t_world;
typedef struct	s_event_manager		t_event_manager;
typedef struct	s_graphic_manager	t_graphic_manager;

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
  long double		time;
  long double		dtime;
  int			tick_delay;
  int			port;
  int			nb_clients;
}			t_info;

typedef struct		s_elevation
{
  unsigned int		res[7];
  int			nb_player;
  unsigned int		lvl_min;
}			t_elevation;

typedef struct		s_server
{
  t_info		info;
  t_event_manager	event_manager;
  t_list		*team_list;
  t_graphic_manager	graphic_manager;
  t_list		*elevation;
  t_param		param;
  t_network		network;
  t_world		*world;
}			t_server;

/*
** FUNCTION
*/
unsigned int	gs_get_map_width(void);
unsigned int	gs_get_map_height(void);
unsigned int	gs_get_map_size(void);

void		time_update(void);

/*
** GLOBAL
*/
t_server	g_server;

#endif		/* !SERVER_H_ */
