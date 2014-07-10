
#include "graphic.h"

bool	graphic_sug(t_graphic *graphic)
{
  return (client_write_to(graphic->client, "sug\n"));
}

bool	graphic_sbp(t_graphic *graphic)
{
  return (client_write_to(graphic->client, "sbp\n"));
}
