#include "print_warning.h"
#include "socket_pool.h"

void			sockpool_update(t_sockpool *pool)
{
  struct timeval	t;

  t.tv_sec = 0;
  t.tv_usec = 0;
  sockpool_fill_sets(pool);
  if (sockpool_filter(pool, &t) != -1)
    sockpool_handle(pool);
  else
    print_pwarning("network sockpool filtering failed");
}
