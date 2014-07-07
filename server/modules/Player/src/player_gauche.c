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

bool	player_gauche(t_player *player,
		      __attribute__ ((unused))char *unused)
{
  void	(*fptr[4])(t_player *);

  fptr[NORTH] = &move_left_north;
  fptr[EAST] = &move_left_east;
  fptr[SOUTH] = &move_left_south;
  fptr[WEST] = &move_left_west;
  fptr[player->orientation.orientation](player);
  return (true);
}
