#include "list.h"

static void	list_filter_rm_node(t_list *list, t_node *prev,
				     t_node **cursor)
{
  t_node	*to_rm;

  to_rm = *cursor;
  *cursor = (*cursor)->next;
  if (to_rm == list->last)
    list->last = prev;
  destroy_node(to_rm, true);
  --list->size;
  if (prev)
    prev->next = *cursor;
  else
    list->nodes = *cursor;
}

void		list_filter(t_list *list, bool (*pred)(void *))
{
  t_node	*cursor;
  t_node	*prev;

  prev = NULL;
  cursor = list_begin(list);
  while (cursor)
    {
      if (pred(cursor->data))
	list_filter_rm_node(list, prev, &cursor);
      else
	{
	  prev = cursor;
	  cursor = cursor->next;
	}
    }
}

void		list_filter_arg(t_list *list, bool (*pred)(void *, void *),
				void *arg)
{
  t_node	*cursor;
  t_node	*prev;

  prev = NULL;
  cursor = list_begin(list);
  while (cursor)
    {
      if (pred(cursor->data, arg))
	list_filter_rm_node(list, prev, &cursor);
      else
	{
	  prev = cursor;
	  cursor = cursor->next;
	}
    }
}
