#include	"world.h"

/* static bool	add_list_player(t_player *player, unsigned int pos)
{
  printf("Add player\n");
  list_push_front(g_server.world->cell[pos].list_player, player);
  printf("Player added\n");
  return (true);
  }*/

bool	spawn_player(const t_sock socket)
{
  /* unsigned int	position; */
  /* t_player	*player; */

  (void)socket;
  printf("Start Spawn player\n");
  /* position = pos.x + (width * pos.y); */
  /* if ((player = create_player(pos, ori, socket)) == NULL || */
  /*     (add_list_player(player, position) == false)) */
  /*   return (false); */
  printf("Spawn player success\n");
  return (true);
}
