/*
** list.h for List in /home/mougen_v/rendus/PSU_2013_zappy/libs/list/inc
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 18:00:30 2014 Valentin
** Last update Sun Jul 13 18:00:31 2014 Valentin
*/

#ifndef		LIST_H_
# define	LIST_H_

# include	<stdlib.h>

# include	"zappy_types.h"

typedef struct	s_node
{
  void		*data;
  struct s_node	*next;
}		t_node;

typedef struct	s_list
{
  int		size;
  t_node	*nodes;
  t_node	*last;
}		t_list;

t_node	*create_node(void *data) __attribute__ ((nonnull));
void	destroy_node(t_node *node, bool free_data)
  __attribute__ ((nonnull));

t_list	*list_create(void);
void	list_destroy(t_list *list, bool free_data)
  __attribute__ ((nonnull));

void	list_clear(t_list *list, bool free_data)
  __attribute__ ((nonnull));

int	list_size(t_list *list) __attribute__ ((nonnull));
bool	list_empty(t_list *list) __attribute__ ((nonnull));

void	*list_front(t_list *list) __attribute__ ((nonnull));
t_node	*list_begin(t_list *list) __attribute__ ((nonnull));

bool	list_push_front(t_list *list, void *data)
  __attribute__ ((nonnull));
void	list_pop_front(t_list *list, bool free_data)
  __attribute__ ((nonnull));

bool	list_push_back(t_list *list, void *data)
  __attribute__ ((nonnull));

bool	list_insert(t_list *list, int pos, void *data)
  __attribute__ ((nonnull));
void	list_remove(t_list *list, void *data, bool free_data)
  __attribute__ ((nonnull));

bool	list_insert_after(t_list *list, t_node *node, void *data)
  __attribute__ ((nonnull));

void	list_for_each(t_list *list, void (*fcn)(void *))
  __attribute__ ((nonnull));
void	list_for_each_arg(t_list *list, void (*fcn)(void *, void *),
			  void *arg) __attribute__ ((nonnull));

void	list_filter(t_list *list, bool (*pred)(void *))
  __attribute__ ((nonnull));
void	list_filter_arg(t_list *list, bool (*pred)(void *, void *),
			void *arg) __attribute__ ((nonnull));

#endif		/* !LIST_H_ */
