/*
** graphic_create.c for zappy in /home/launoi_a/tmp/PSU_2013_zappy/server/modules/Graphic
** 
** Made by allyriane.launois
** Login   <launoi_a@epitech.net>
** 
** Started on  Sun Jul 13 18:36:53 2014 allyriane.launois
** Last update Sun Jul 13 18:37:27 2014 allyriane.launois
*/

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

static void	graphic_connexion(t_graphic *graph)
{
  t_node	*tmp_list;
  t_node	*tmp_player;

  client_write_to(graph->client, "BIENVENUE\n");
  graphic_msz(graph, NULL);
  graphic_sgt(graph, NULL);
  graphic_mct(graph, NULL);
  graphic_tna(graph, NULL);
  for (tmp_list = list_begin(g_server.team_list); tmp_list;
       tmp_list = tmp_list->next)
    for (tmp_player = list_begin(((t_team *)tmp_list->data)->members);
	 tmp_player; tmp_player = tmp_player->next)
      graphic_pnw(graph, tmp_player->data);
  for (tmp_list = list_begin(g_server.team_list); tmp_list;
       tmp_list = tmp_list->next)
    for (tmp_player = list_begin(((t_team *)tmp_list->data)->eggs);
	 tmp_player; tmp_player = tmp_player->next)
      graphic_pnw(graph, tmp_player->data);
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
  graphic_connexion(new_graph);
  return (new_graph);
}
