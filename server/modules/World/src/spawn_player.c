#include	"world.h"

static bool	add_list_player(t_player *player, unsigned int pos)
{
  printf("Add player\n");
  list_push_front(g_server.world->cell[pos].list_player, player);
  printf("Player added\n");
  return (true);
}

bool	spawn_player(const t_sock socket)
{
  unsigned int	height;
  unsigned int	width;
  unsigned int	position;;
  t_vector	pos;
  enum e_ori	ori;
  t_player	*player;

  printf("Start Spawn player\n");
  height = g_server.world->height;
  width = g_server.world->width;
  pos.x = rand() % width;
  pos.y = rand() % height;
  position = pos.x + (width * pos.y);
  ori = rand() % 4;
  if ((player = create_player(pos, ori, socket)) == NULL ||
      (add_list_player(player, position) == false))
    return (false);
  printf("Spawn player success\n");
  return (true);
}
