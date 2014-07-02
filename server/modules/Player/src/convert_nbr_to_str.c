#include "world.h"

static char	*nbr_to_str(int pow, int size, int nbr)
{
  char		*str;
  int		value;
  int		i;

  if ((str = malloc((size + 1) * sizeof(char))) == NULL)
    return (NULL);
  i = 0;
  value = 0;
  while (size > 0)
    {
      str[i] = '0' + (nbr / pow);
      value = (nbr / pow) * pow;
      nbr -= value;
      pow /= 10;
      --size;
      i++;
    }
  str[i] = 0;
  return (str);
}

char	*convert_nbr_to_str(int nbr)
{
  int		pow;
  int		size;

  size = 1;
  pow = 10;
  while (pow <= nbr)
    {
      ++size;
      if (pow == nbr)
	return (nbr_to_str(pow, size, nbr));
      else
	pow *= 10;
    }
  pow /= 10;
  return (nbr_to_str(pow, size, nbr));
}
