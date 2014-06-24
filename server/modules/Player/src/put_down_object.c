#include "world.h"

static int	string_to_res(const char *res)
{
  int		i;

  i = 0;
  while (res_name[i] != NULL)
    {
      if (strcmp(res, res_name[i]) == 0)
	return (i);
      ++i;
    }
  return (-1);
}

