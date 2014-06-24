#include	"player.h"

static void	orientation_north(t_orientation *player_ori)
{
  player_ori->orientation = NORTH;
  player_ori->vec.x = 0;
  player_ori->vec.y = -1;
}

static void	orientation_south(t_orientation *player_ori)
{
  player_ori->orientation = SOUTH;
  player_ori->vec.x = 0;
  player_ori->vec.y = 1;
}

static void	orientation_east(t_orientation *player_ori)
{
  player_ori->orientation = EAST;
  player_ori->vec.x = 1;
  player_ori->vec.y = 0;
}

static void	orientation_west(t_orientation *player_ori)
{
  player_ori->orientation = WEST;
  player_ori->vec.x = -1;
  player_ori->vec.y = 0;
}

void	set_orientation(t_player *player, const enum e_ori ori)
{
  void	(*fptr[4])(t_orientation *);

  fptr[0] = &orientation_north;
  fptr[1] = &orientation_east;
  fptr[2] = &orientation_south;
  fptr[3] = &orientation_west;
  fptr[ori](&(player->orientation));
}
