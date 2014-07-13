/*
** team_list_destroy.c for zappy in /home/launoi_a/tmp/PSU_2013_zappy/server/modules/Team
** 
** Made by allyriane.launois
** Login   <launoi_a@epitech.net>
** 
** Started on  Sun Jul 13 19:00:11 2014 allyriane.launois
** Last update Sun Jul 13 19:00:18 2014 allyriane.launois
*/

#include "print_log.h"
#include "server.h"
#include "team.h"

static void	team_list_node_destroy(void *node)
{
  team_destroy(node);
}

void	team_list_destroy(void)
{
  print_log("Deleting teams...");
  if (g_server.team_list)
    {
      list_for_each(g_server.team_list, &team_list_node_destroy);
      list_clear(g_server.team_list, false);
      free(g_server.team_list);
    }
}
