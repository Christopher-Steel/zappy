#include	"world.h"
#include	"server.h"
#include	"print_log.h"
#include	"print_error.h"

static bool	add_list_player(t_player *player, unsigned int pos)
{
  bool		is_succed;

  is_succed = list_push_front(&g_server.world.cell[pos].list_player, player);
  if (!is_succed)
    {
      print_error("Cannot spawn player");
      free(player);
    }
  return (is_succed);
}

t_player	*spawn_player(t_client *client, t_team *team)
{
  unsigned int	height;
  unsigned int	width;
  unsigned int	position;
  enum e_ori	ori;
  t_vector	pos;
  t_player	*player;

  height = gs_get_map_height();
  width = gs_get_map_width();
  pos.x = rand() % width;
  pos.y = rand() % height;
  position = pos.x + (width * pos.y);
  ori = rand() % 4;
  if ((player = create_player(pos, ori, client, team)) == NULL ||
      (add_list_player(player, position) == false))
      return (NULL);
  return (player);
}
