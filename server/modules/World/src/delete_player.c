/*
** delete_player.c for zappy in /home/launoi_a/tmp/PSU_2013_zappy/server/modules/World
** 
** Made by allyriane.launois
** Login   <launoi_a@epitech.net>
** 
** Started on  Sun Jul 13 19:15:15 2014 allyriane.launois
** Last update Sun Jul 13 19:15:21 2014 allyriane.launois
*/

#include "server.h"
#include "world.h"

void		delete_player(t_player *player)
{
  int		pos;
  t_node	*free_node;
  t_node	*tmp;

  pos = player->pos.x + (player->pos.y * gs_get_map_width());
  tmp = g_server.world.cell[pos].list_player.nodes;
  while (tmp->next != NULL)
    {
      if (((t_player *)(tmp->data))->id == player->id)
	{
	  --g_server.world.cell[pos].list_player.size;
	  free_node = tmp;
	  tmp = tmp->next->next;
	  destroy_node(free_node, true);
	}
      else
	tmp = tmp->next;
    }
}
