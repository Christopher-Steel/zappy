#include	"world.h"

static t_list_player	*add_list_player(t_player *player, unsigned int pos)
{
  t_list_player		*new_node;

  printf("Add player\n");
  if ((new_node = malloc(sizeof(t_list_player))) == NULL)
    return (NULL);
  new_node->player = player;
  new_node->next = g_server.world->cell[pos].list_player;
  g_server.world->cell[pos].list_player = new_node;
  printf("Player added\n");
  return (new_node);
}

bool	spawn_player(const t_sock socket, const int id)
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
  if ((player = create_player(pos, ori, socket, id)) == NULL ||
      (add_list_player(player, position) == NULL))
    return (false);
  printf("Spawn player success\n");
  return (true);
}
