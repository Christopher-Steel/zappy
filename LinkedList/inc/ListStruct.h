#ifndef		LISTSTRUCT_H_
# define	LISTSTRUCT_H_

# include	<stdlib.h>
# include	<stdbool.h>

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

/*
** CreateDestroyNode.c
*/
t_node	*create_node(void *data);
void	destroy_node(t_node *node);

/*
** CreateDestroyList.c
*/
t_list	*create_list(void);
void	destroy_list(t_list *list);

/*
** PushPopFront.c
*/
bool	push_front(t_list *list, void *data);
void	pop_front(t_list *list);

/*
** InsertRemove.c
*/
bool	insert(t_list *list, int pos, void *data);
void	remove(t_list *list, void *data);

/*
** ForEach.c
*/
void	for_each(t_list *list, void (*fcn)(void *));
void	for_each_arg(t_list *list, void (*fcn)(void *, void *), void *param);

#endif		/* !LISTSTRUCT_H_ */
