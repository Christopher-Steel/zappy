#include "world.h"

static void   	remove_last(const int id, const int position)
{
  if (g_server.world->cell[position].list_player->player->id == id)
    {
      free(g_server.world->cell[position].list_player);
      g_server.world->cell[position].list_player = NULL;
    }
}

void		remove_player(const int id, const int position)
{
  unsigned int	nbr;
  t_list_player	*tmp;
  t_list_player	*free_node;


  tmp = g_server.world->cell[position].list_player;
  nbr = listlen(tmp);
  if(nbr == 0)
    return ;
  else if (nbr == 1)
    remove_last(id, position);
  else
    {
      while (tmp->next != NULL)
	{
	  if (tmp->player->id == id)
	    {
	      free_node = tmp;
	      tmp = tmp->next->next;
	      free(free_node);
	      free_node = NULL;
	    }
	  else
	    tmp = tmp->next;
	}
    }
}
