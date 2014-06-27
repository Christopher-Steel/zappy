#ifndef		LIST_H_
# define	LIST_H_

# include	<stdlib.h>

# include	"zappy_types.h"
# include	"print_error.h"

typedef struct	s_node
{
  void		*data;
  struct s_node	*next;
}		t_node;

typedef struct	s_list
{
  int		size;
  t_node	*nodes;

}		t_list;

t_node	*create_node(void *data) __attribute__ ((nonnull (1)));
void	destroy_node(t_node *node, bool free_data)
  __attribute__ ((nonnull (1)));

t_list	*list_create(void);
void	list_destroy(t_list *list, bool free_data)
  __attribute__ ((nonnull (1)));

int	list_size(t_list *list) __attribute__ ((nonnull (1)));

void	*list_front(t_list *list) __attribute__ ((nonnull (1)));

bool	list_push_front(t_list *list, void *data)
  __attribute__ ((nonnull (1, 2)));
void	list_pop_front(t_list *list, bool free_data)
  __attribute__ ((nonnull (1)));

bool	list_push_back(t_list *list, void *data)
  __attribute__ ((nonnull (1, 2)));

bool	list_insert(t_list *list, int pos, void *data)
  __attribute__ ((nonnull (1, 3)));
void	list_remove(t_list *list, void *data, bool free_data)
  __attribute__ ((nonnull (1, 2)));

void	list_for_each(t_list *list, void (*fcn)(void *))
  __attribute__ ((nonnull (1)));
void	list_for_each_arg(t_list *list, void (*fcn)(void *, void *), void *param);

#endif		/* !LIST_H_ */
