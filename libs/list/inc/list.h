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

}		t_list;

t_node	*create_node(void *data);
void	destroy_node(t_node *node);

t_list	*list_create(void);
void	list_destroy(t_list *list);

bool	list_push_front(t_list *list, void *data);
void	list_pop_front(t_list *list);

bool	list_insert(t_list *list, int pos, void *data);
void	list_remove(t_list *list, void *data);

void	list_for_each(t_list *list, void (*fcn)(void *));
void	list_for_each_arg(t_list *list, void (*fcn)(void *, void *), void *param);

#endif		/* !LIST_H_ */
