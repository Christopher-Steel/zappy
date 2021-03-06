/*
** graph_pose_prend.c for zappy in /home/launoi_a/tmp/PSU_2013_zappy/server/modules/GraphProtocol
** 
** Made by allyriane.launois
** Login   <launoi_a@epitech.net>
** 
** Started on  Sun Jul 13 18:55:04 2014 allyriane.launois
** Last update Sun Jul 13 18:55:17 2014 allyriane.launois
*/

#include "graph_PI.h"

bool	graph_prend(void *player, void *obj)
{
  void	**tab;

  if (!(tab = mount_args(player, obj))
      || !graph_for_each_2_args(&graphic_pgt, tab))
    return (false);
  if (!graph_for_each_1_arg(&graphic_pin2, player))
    return (false);
  if (!(tab = mount_args(&(((t_player *)player)->pos.x),
			 &(((t_player *)player)->pos.y)))
      || graph_for_each_2_args(&graphic_bct2, tab))
    return (false);
  return (true);
}

bool	graph_pose(void *player, void *obj)
{
  void	**tab;

  if (!(tab = mount_args(player, obj))
      || !graph_for_each_2_args(&graphic_pdr, tab))
    return (false);
  if (!graph_for_each_1_arg(&graphic_pin2, player))
    return (false);
  if (!(tab = mount_args(&(((t_player *)player)->pos.x),
			 &(((t_player *)player)->pos.y)))
      || graph_for_each_2_args(&graphic_bct2, tab))
    return (false);
  return (true);
}
