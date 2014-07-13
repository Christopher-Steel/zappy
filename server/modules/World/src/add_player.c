/*
** add_player.c for zappy in /home/launoi_a/tmp/PSU_2013_zappy/server/modules/World
** 
** Made by allyriane.launois
** Login   <launoi_a@epitech.net>
** 
** Started on  Sun Jul 13 19:15:06 2014 allyriane.launois
** Last update Sun Jul 13 19:15:10 2014 allyriane.launois
*/

#include "server.h"
#include "world.h"

bool	add_player(t_player *player, const int pos)
{
  return (list_push_front(&g_server.world.cell[pos].list_player, player));
}
