/*
** graphic_invalid_cmd.c for zappy in /home/launoi_a/tmp/PSU_2013_zappy/server/modules/Graphic
** 
** Made by allyriane.launois
** Login   <launoi_a@epitech.net>
** 
** Started on  Sun Jul 13 18:38:54 2014 allyriane.launois
** Last update Sun Jul 13 18:38:59 2014 allyriane.launois
*/

#include "graphic.h"

bool	graphic_suc(t_graphic *graphic)
{
  return (client_write_to(graphic->client, "suc"));
}

bool	graphic_sbp(t_graphic *graphic)
{
  return (client_write_to(graphic->client, "sbp"));
}
