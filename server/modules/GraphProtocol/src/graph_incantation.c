
#include "graph_PI.h"

void		**mount_player_tab(t_list *players)
{
  int		i;
  t_node	*node;
  void		**tab;

  if (!(tab = malloc(sizeof(t_player *) * (players->size + 1))))
    return (NULL);
  i = -1;
  for (node = list_begin(players); node; node = node->next)
      tab[++i] = node->data;
  tab[++i] = NULL;
  return (tab);
}

bool		graph_incantation(t_list *players)
{
  void		**tab;

  if (!(tab = mount_player_tab(players))
      || graph_for_each_1_arg(&graphic_pic, tab))
    return (false);
  free(tab);
  return (true);
}

bool		graph_end_incantation(t_player *player, t_list *players, int result)
{
  t_node	*node;
  void		**tab;

  tab = mount_args(player, &result);
  graph_for_each_2_args(&graphic_pie, tab);
  for (node = list_begin(players); node; node = node->next)
    graph_for_each_1_arg(&graphic_plv2, node->data);
  for (node = list_begin(players); node; node = node->next)
    {
      tab = mount_args(&(((t_player *)node->data)->pos.x),
		       &(((t_player *)node->data)->pos.y));
      graph_for_each_2_args(&graphic_bct2, tab);
    }
  return (true);
}
