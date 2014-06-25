void			sockpool_handle(t_sockpool *pool)
{
  t_sockpool_node	*node;
  uint			handled;

  if (pool->nbset <= 0)
    return ;
  if (FD_ISSET(pool->listener, pool->read_set))
    add_client(pool, pool->listener);
  handled = 0;
  for (node = pool->nodes; handled < pool->nbset && node; node = node->next)
    {
      if (FD_ISSET(node->socket, pool->read_set))
	{
	  handle_read(node);
	  ++handled;
	}
      if (FD_ISSET(node->socket, pool->write_set))
	{
	  handle_write(node);
	  ++handled;
	}
    }
}
