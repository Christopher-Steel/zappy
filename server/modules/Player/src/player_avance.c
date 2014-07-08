#include	"print_error.h"
#include	"print_log.h"
#include	"world.h"

bool		player_avance(t_player *player,
			      __attribute__ ((unused))char *unused)
{
  t_vector	vec;
  int		pos_init;
  int		pos_final;

  pos_init = player->pos.x + (player->pos.y * gs_get_map_width());
  vec = get_vec_direction(player->ori);
  player->pos.x += vec.x;
  player->pos.y += vec.y;
  player->pos = wrap_vertical(player->pos);
  player->pos = wrap_horizontal(player->pos);
  pos_final = player->pos.x + (player->pos.y * gs_get_map_width());
  remove_player(player->id, pos_init);
  add_player(player, pos_final);
  return (client_write_to(player->client, "ok"));
}
