/*
** empty.c for List in /home/mougen_v/rendus/PSU_2013_zappy/libs/list/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 18:02:36 2014 Valentin
** Last update Sun Jul 13 18:02:37 2014 Valentin
*/

#include "list.h"

bool	list_empty(t_list *list)
{
  return ((list->size == 0));
}
