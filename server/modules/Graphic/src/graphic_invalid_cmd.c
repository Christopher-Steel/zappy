
#include "graphic.h"

bool	graphic_suc(t_graphic *graphic)
{
  return (client_write_to(graphic->client, "suc\n"));
}

bool	graphic_sbp(t_graphic *graphic)
{
  return (client_write_to(graphic->client, "sbp\n"));
}
