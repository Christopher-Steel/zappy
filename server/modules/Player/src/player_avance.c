#include	"print_error.h"
#include	"print_log.h"
#include	"world.h"

static void	wrap_border_map_horizontally(t_player *player, t_world *world)
{
  unsigned int	pos;

  pos = player->pos.x;
  if (player->pos.x < 0)
    player->pos.x = world->width - 1;
  else if (pos >= world->width)
    player->pos.x = 0;
}

static void	wrap_border_map_vertically(t_player *player, t_world *world)
{
  unsigned int	pos;

  pos = player->pos.y;
  if (player->pos.y < 0)
    player->pos.y = world->height - 1;
  else if (pos >= world->height)
    player->pos.y = 0;
}

bool		player_avance(t_player *player,
			      __attribute__ ((unused))char *unused)
{
  t_world	*world;
  t_vector	vec;
  int		pos_init;
  int		pos_final;
  unsigned int	pos_x;
  unsigned int	pos_y;

  world = g_server.world;
  pos_init = player->pos.x + (player->pos.y * gs_get_map_width());
  vec = get_vec_direction(player->ori);
  player->pos.x += vec.x;
  player->pos.y += vec.y;
  pos_x = player->pos.x;
  pos_y = player->pos.y;
  if (player->pos.x < 0 || pos_x >= world->width)
    wrap_border_map_horizontally(player, world);
  if (player->pos.y < 0 || pos_y >= world->height)
    wrap_border_map_vertically(player, world);
  pos_final = player->pos.x + (player->pos.y * gs_get_map_width());
  remove_player(player->id, pos_init);
  add_player(player, pos_final);
  return (true);
}