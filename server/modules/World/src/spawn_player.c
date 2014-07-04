#include	"world.h"
#include	"print_log.h"
#include	"print_error.h"

static bool	add_list_player(t_player *player, unsigned int pos)
{
  bool		is_succed;

  is_succed = list_push_front(g_server.world->cell[pos].list_player, player);
  if (!is_succed)
    {
      print_error("Cannot spawn player");
      free(player);
    }
  return (is_succed);
}

t_player	*spawn_player(t_client *client)
{
  unsigned int	height;
  unsigned int	width;
  unsigned int	position;
  enum e_ori	ori;
  t_vector	pos;
  t_player	*player;

  height = g_server.world->height;
  width = g_server.world->width;
  pos.x = rand() % width;
  pos.y = rand() % height;
  position = pos.x + (width * pos.y);
  ori = rand() % 4;
  if ((player = create_player(pos, ori, client)) == NULL ||
      (add_list_player(player, position) == false))
      return (NULL);
  return (player);
}
