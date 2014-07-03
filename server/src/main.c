#include <signal.h>
#include <stdlib.h>

#include "network.h"
#include "parse_parameter.h"
#include "print_error.h"

static void	sigint_handler(__attribute__ ((unused))int sig)
{
  exit(0);
}

int	main(int ac, char *av[])
{
  signal(SIGINT, &sigint_handler);
  signal(SIGHUP, &sigint_handler);
  parse_param(ac, av);
  if (network_init(g_server.info.port))
    while (1)
      network_update();
  network_shutdown(0, NULL);
  return (0);
}
