#include "server.h"
#include "world.h"

static void   	point_north(t_vision vision, int *tab, int *j)
{
  t_vector	angle;
  t_vector	pos;
  int		pos_case;

  angle.x = vision.dist;
  angle.y = 0;
  vision.start = sub_vector(vision.pos, angle);
  vision.end = add_vector(vision.pos, angle);
  pos = wrap_horizontal(vision.start);
  pos_case = pos.x + (pos.y * gs_get_map_width());
  tab[(*j)] = pos_case;
  angle.x = 1;
  ++(*j);
  while (!equal_vector(vision.start, vision.end))
    {
      vision.start = add_vector(vision.start, angle);
      pos = wrap_horizontal(vision.start);
      pos_case = pos.x + (pos.y * gs_get_map_width());
      tab[(*j)] = pos_case;
      ++(*j);
    }
}

static void   	point_east(t_vision vision, int *tab, int *j)
{
  t_vector	angle;
  t_vector	pos;
  int		pos_case;

  angle.x = 0;
  angle.y = -vision.dist;
  vision.start = sub_vector(vision.pos, angle);
  vision.end = add_vector(vision.pos, angle);
  pos = wrap_vertical(vision.start);
  pos_case = pos.x + (pos.y * gs_get_map_width());
  tab[(*j)] = pos_case;
  angle.y = -1;
  ++(*j);
  while (!equal_vector(vision.start, vision.end))
    {
      vision.start = add_vector(vision.start, angle);
      pos = wrap_vertical(vision.start);
      pos_case = pos.x + (pos.y * gs_get_map_width());
      tab[(*j)] = pos_case;
      ++(*j);
    }
}

static void   	point_south(t_vision vision, int *tab, int *j)
{
  t_vector	angle;
  t_vector	pos;
  int		pos_case;

  angle.x = -vision.dist;
  angle.y = 0;
  vision.start = sub_vector(vision.pos, angle);
  vision.end = add_vector(vision.pos, angle);
  pos = wrap_horizontal(vision.start);
  pos_case = pos.x + (pos.y * gs_get_map_width());
  tab[(*j)] = pos_case;
  angle.x = -1;
  ++(*j);
  while (!equal_vector(vision.start, vision.end))
    {
      vision.start = add_vector(vision.start, angle);
      pos = wrap_horizontal(vision.start);
      pos_case = pos.x + (pos.y * gs_get_map_width());
      tab[(*j)] = pos_case;
      ++(*j);
    }
}

static void   	point_west(t_vision vision, int *tab, int *j)
{
  t_vector	angle;
  t_vector	pos;
  int		pos_case;

  angle.x = 0;
  angle.y = vision.dist;
  vision.start = sub_vector(vision.pos, angle);
  vision.end = add_vector(vision.pos, angle);
  pos = wrap_vertical(vision.start);
  pos_case = pos.x + (pos.y * gs_get_map_width());
  tab[(*j)] = pos_case;
  angle.y = 1;
  ++(*j);
  while (!equal_vector(vision.start, vision.end))
    {
      vision.start = add_vector(vision.start, angle);
      pos = wrap_vertical(vision.start);
      pos_case = pos.x + (pos.y * gs_get_map_width());
      tab[(*j)] = pos_case;
      ++(*j);
    }
}

void		get_vision_point(int *tab, t_player *player)
{
  t_vision	vision;
  int		j;
  unsigned int	i;
  void		(*fptr[4])(t_vision, int *, int *);

  i = 0;
  j = 0;
  fptr[NORTH] = &point_north;
  fptr[EAST] = &point_east;
  fptr[SOUTH] = &point_south;
  fptr[WEST] = &point_west;
  vision.pos = player->pos;
  while (i <= player->level)
    {
      vision.dist = i;
      fptr[player->ori](vision, tab, &j);
      vision.pos = add_vector(vision.pos, get_vec_direction(player->ori));
      vision.pos = wrap_vertical(vision.pos);
      vision.pos = wrap_horizontal(vision.pos);
      ++i;
    }
  tab[j] = -1;
}
