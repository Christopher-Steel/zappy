#include "print_log.h"
#include "world.h"

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
  t_node	*free_node;

  while (tmp != NULL)
    {
      if (((t_player *)(tmp->data))->id == id)
	{
	  --g_server.world->cell[position].list_player->size;
	  free_node = tmp;
	  if (tmp->next == NULL)
	    tmp = NULL;
	  else
	    tmp = tmp->next->next;
	  destroy_node(free_node, false);
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
