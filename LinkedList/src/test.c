
#include "ListStruct.h"

void	print(void *elem)
{
  printf("%s ", elem);
}


void	print_arg(void *elem, void *param)
{
  printf("%s/%s ", elem, param);
}

void	main(void)
{
  t_list	*list;
  void		*data;

  list = create_list();
  asprintf(&data, "%s", "!");
  push_front(list, data);
  asprintf(&data, "%s", "toto");
  push_front(list, data);
  asprintf(&data, "%s", "suis");
  push_front(list, data);
  asprintf(&data, "%s", "je");
  push_front(list, data);
  asprintf(&data, "%s", "hello");
  push_front(list, data);

  for_each(list, &print);
  printf("\n");
  /*
  ** result = "hello je suis toto ! "\n
  */

  pop_front(list);
  asprintf(&data, "%s", "bonjour");
  push_front(list, data);

  for_each(list, &print);
  printf("\n");
  /*
  ** result = "bonjour je suis toto ! "\n
  */

  asprintf(&data, "%s", "test");
  insert(list, 2, data);

  for_each(list, &print);
  printf("\n");
  /*
  ** result = "bonjour test je suis toto ! "\n
  */

  remove(list, data);

  for_each_arg(list, &print_arg, "node");
  printf("\n");
  /*
  ** result = "bonjour/node je/node suis/node toto/node !/node "\n
  */
  destroy_list(list);
}
