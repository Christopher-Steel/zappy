
#include "graph_PI.h"
#include "print_error.h"
#include "server.h"

void	**mount_args(void *arg1, void *arg2)
{
  void	**tab;

  if (!(tab = malloc(sizeof(void*) * 2)))
    {
      print_error("failed to allocate args table");
      return (NULL);
    }
  tab[0] = arg1;
  tab[1] = arg2;
  return (tab);
}

bool		graph_for_each(t_list *graphics, bool (*func)(t_graphic *))
{
  t_node	*node;

  for (node = list_begin(graphics); node; node = node->next)
    if (!func(node->data))
      return (false);
  return (true);
}

bool		graph_for_each_1_arg(t_list *graphics,
				     bool (*func)(t_graphic *, void *), void *arg)
{
  t_node	*node;

  for (node = list_begin(graphics); node; node = node->next)
    if (!func(node->data, arg))
      return (false);
  return (true);
}

bool		graph_for_each_2_args(t_list *graphics,
				      bool (*func)(t_graphic *, void *, void *),
				      void **args)
{
  t_node	*node;

  for (node = list_begin(graphics); node; node = node->next)
    if (!func(node->data, args[0], args[1]))
      {
	free(args);
	return (false);
      }
  free(args);
  return (true);

}
