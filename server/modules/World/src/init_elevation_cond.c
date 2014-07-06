#include "world.h"
#include "list.h"

bool	init_elevation_cond(void)
{
  int	i;
  bool	(*fptr[7])(void);

  i = 0;
  fptr[0] = &up_two;
  fptr[1] = &up_three;
  fptr[2] = &up_four;
  fptr[3] = &up_five;
  fptr[4] = &up_six;
  fptr[5] = &up_seven;
  fptr[6] = &up_height;
  g_server.elevation = list_create();
  while (i < 7)
    if (!fptr[i++]())
      return (false);
  return (true);
}
