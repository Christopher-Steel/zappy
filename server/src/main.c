/*
** main.c for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/src
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 18:12:03 2014 Valentin
** Last update Sun Jul 13 18:12:06 2014 Valentin
*/

#include <signal.h>
#include <stdlib.h>

#include "network.h"
#include "parse_parameter.h"
#include "print_error.h"
#include "server.h"
#include "player.h"
#include "time.h"
#include "zappy_types.h"

static void	sigint_handler(__attribute__ ((unused))int sig)
{
  exit(0);
}

static void	setup_sighandlers(void)
{
  signal(SIGINT, &sigint_handler);
  signal(SIGHUP, &sigint_handler);
  signal(SIGPIPE, SIG_IGN);
}

static void	stop_services(void)
{
  event_manager_shutdown();
  graphic_manager_shutdown();
  team_list_destroy();
  network_shutdown();
}

static bool	start_services(void)
{
  srand(time(NULL));
  event_manager_init();
  graphic_manager_init();
  generate_world(g_server.param.height, g_server.param.width);
  team_list_init();
  return (network_init(g_server.info.port));
}

int	main(int ac, char *av[])
{
  atexit(&stop_services);
  setup_sighandlers();
  parse_param(ac, av);
  if (start_services())
    while (!victory_condition_resolve())
      {
	gs_time_update();
	player_life_update();
	network_update();
	gs_event_update();
      }
  return (0);
}
