#include "socket_pool.h"

bool	sockpool_filter(t_sockpool *pool, struct timeval *time)
{
  return (((pool->nbset = select(pool->maxfd + 1, &pool->read_set,
				 &pool->write_set, NULL, t)) == -1
	   ? false : true));
}
