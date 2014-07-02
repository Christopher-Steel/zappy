#include "player.h"

static void	move_left_north(t_player *player)
{
  set_orientation(player, WEST);
}

static void	move_left_east(t_player *player)
{
  set_orientation(player, NORTH);
}

static void	move_left_south(t_player *player)
{
  set_orientation(player, EAST);
}

static void	move_left_west(t_player *player)
{
  set_orientation(player, SOUTH);
}

bool	move_left(t_player *player, char *cmd)
{
  void	(*fptr[4])(t_player *);

  (void)cmd;
  fptr[NORTH] = &move_left_north;
  fptr[EAST] = &move_left_east;
  fptr[SOUTH] = &move_left_south;
  fptr[WEST] = &move_left_west;
  fptr[player->orientation.orientation](player);
  return (true);
}
