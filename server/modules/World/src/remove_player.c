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

void		remove_player(const int id, const int position)
{
  unsigned int	nbr;
  t_node	*tmp;
  t_node	*free_node;


  tmp = g_server.world->cell[position].list_player->nodes;
  nbr = g_server.world->cell[position].list_player->size;
  if(nbr == 0)
    return ;
  else if (nbr == 1)
    remove_last(id, position);
  else
    {
      while (tmp->next != NULL)
	{
	  if (((t_player *)(tmp->data))->id == id)
	    {
	      free_node = tmp;
	      tmp = tmp->next->next;
	      free(free_node);
	      free_node = NULL;
	      --g_server.world->cell[position].list_player->size;
	    }
	  else
	    tmp = tmp->next;
	}
    }
}
