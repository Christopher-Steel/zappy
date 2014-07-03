#include "print_log.h"
#include "socket_pool.h"

void			sockpool_handle(t_sockpool *pool)
{
  t_node		*lnode;
  t_sockpool_node	*snode;

  if (pool->nbset <= 0)
    return ;
  if (FD_ISSET(pool->listener, &pool->read_set))
    sockpool_add_client(pool, pool->listener);
  for (lnode = pool->nodes.nodes; pool->nbset > 0 && lnode;
       lnode = lnode->next)
    {
      snode = (t_sockpool_node *)lnode->data;
      if (FD_ISSET(snode->socket, &pool->read_set))
	{
	  sockpool_node_read(snode);
	  --pool->nbset;
	}
      if (FD_ISSET(snode->socket, &pool->write_set))
	{
	  sockpool_node_write(snode);
	  --pool->nbset;
	}
    }
}
