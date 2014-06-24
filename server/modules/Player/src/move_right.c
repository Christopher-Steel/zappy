#include "player.h"

static void	move_right_north(t_player *player)
{
  set_orientation(player, EAST);
}

static void	move_right_east(t_player *player)
{
  set_orientation(player, SOUTH);
}

static void	move_right_south(t_player *player)
{
  set_orientation(player, WEST);
}

static void	move_right_west(t_player *player)
{
  set_orientation(player, NORTH);
}

void	move_right(t_player *player, char *cmd)
{
  void	(*fptr[4])(t_player *);

  (void)cmd;
  fptr[0] = &move_right_north;
  fptr[1] = &move_right_east;
  fptr[2] = &move_right_south;
  fptr[3] = &move_right_west;
  fptr[player->orientation.orientation](player);
}
