#include "print_log.h"
#include "world.h"

static void	remove_in_list(t_node *tmp, const int position)
{
  t_node	*free_node;

  --g_server.world->cell[position].list_player->size;
  free_node = tmp->next;
  tmp->next = tmp->next->next;
  destroy_node(free_node, false);
}

static void	remove_front_list(t_node *tmp, const int position)
{
  t_node	*free_node;

  --g_server.world->cell[position].list_player->size;
  free_node = tmp;
  tmp = tmp->next;
  destroy_node(free_node, false);
}

static void   	remove_last(const int id, const int position)
{
  t_node	*nodes;

  nodes = g_server.world->cell[position].list_player->nodes;
  if (((t_player *)nodes->data)->id == id)
    {
      free(g_server.world->cell[position].list_player->nodes);
      g_server.world->cell[position].list_player->nodes = NULL;
      --g_server.world->cell[position].list_player->size;
    }
}

static void	remove_case(const int id, const int position,
			    t_node *tmp)
{
  if (((t_player *)tmp->data)->id == id)
    remove_front_list(tmp, position);
  else
    while (tmp != NULL)
      {
	if (tmp->next != NULL &&
	    ((t_player *)tmp->next->data)->id == id)
	  {
	    remove_in_list(tmp, position);
	    return ;
	  }
	else
	  tmp = tmp->next;
      }
}

void		remove_player(const int id, const int position)
{
  t_node	*tmp;
  unsigned int	nbr;

  tmp = g_server.world->cell[position].list_player->nodes;
  nbr = g_server.world->cell[position].list_player->size;
  if (nbr == 0)
    return ;
  else if (nbr == 1)
    remove_last(id, position);
  else
    remove_case(id, position, tmp);
}
