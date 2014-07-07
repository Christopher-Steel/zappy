#include "print_log.h"
#include "world.h"

static void	inform_expulsed_player(t_player *player)
{
  printf_log("player %d move to %d, %d", player->id, player->pos.x, player->pos.y);
}

static void	expulsing(t_node *node, t_player *player,
			  unsigned int pos_init, t_vector vec_dest)
{
  t_player	*expulsed;
  unsigned int	pos_final;

  printf_log("player %d expulsant", player->id);
  pos_final = vec_dest.x + (vec_dest.y * gs_get_map_width());
  while (node != NULL)
    {
      if (node != NULL && ((t_player *)node->data)->id != player->id)
	{
	  expulsed = ((t_player *)node->data);
	  remove_player(expulsed->id, pos_init);
	  add_player(expulsed, pos_final);
	  node = node->next;
	  expulsed->pos = vec_dest;
	  inform_expulsed_player(expulsed);
	}
      else
	node = node->next;
    }
}

bool		player_expulse(t_player *player,
			       __attribute__ ((unused))char *unused)
{
  t_world	*world;
  t_node	*node;
  t_vector	vec_dest;
  unsigned int	pos_init;

  world = g_server.world;
  vec_dest = add_vector(player->pos, player->orientation.vec);
  vec_dest = wrap_vertical(vec_dest);
  vec_dest = wrap_horizontal(vec_dest);
  pos_init = player->pos.x + (player->pos.y * gs_get_map_width());
  node = world->cell[pos_init].list_player->nodes;
  if (world->cell[pos_init].list_player->size > 1)
    expulsing(node, player, pos_init, vec_dest);
  return (true);
}
