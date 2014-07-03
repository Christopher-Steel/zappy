#include "graphic.h"
#include "print_debug.h"
#include "print_error.h"

static void	graphic_receive(__attribute__ ((unused))t_receiver *rec,
				char *msg)
{
  printf_debug("graphic received: %s", msg);
}

static void	graphic_destroy(t_receiver *rec)
{
  t_graphic	*graphic;

  graphic = (t_graphic *)rec;
  free(graphic);
}

t_graphic	*graphic_create(t_client *client)
{
  t_graphic	*new_graph;

  if ((new_graph = malloc(sizeof(*new_graph))) == NULL)
    {
      print_perror("failed to create new graphic handle");
      return (NULL);
    }
  new_graph->receive = &graphic_receive;
  new_graph->destroy = &graphic_destroy;
  new_graph->client = client;
  return (new_graph);
}
