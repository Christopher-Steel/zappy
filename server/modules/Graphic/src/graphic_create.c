#include <stdlib.h>

#include "graphic.h"
#include "graph_PI.h"
#include "print_debug.h"
#include "print_error.h"
#include "server.h"

static void	graphic_receive(t_receiver *rec, char *msg)
{
  t_graphic	*graphic;

  printf_debug("graphic received: %s", msg);
  graphic = (t_graphic *)rec;
  graph_PI(graphic, msg);
}

static void	graphic_destroy(t_receiver *rec)
{
  list_remove(&g_server.graphic_manager.graphic_handlers, rec, true);
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
  list_push_back(&g_server.graphic_manager.graphic_handlers, new_graph);
  return (new_graph);
}
