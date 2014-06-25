#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

# define	CLIENT_PROMPT	"\033[1;36mKirbyHelper \033[35m(>'.')>\033[0m "

bool		player_voir(t_player *player, char *arg)
{
  (void)player;
  (void)arg;
  printf("voir found\n");
  return (true);
}

bool		player_avance(t_player *player, char *arg)
{
  (void)player;
  (void)arg;
  printf("avance found\n");
  return (true);
}

bool		player_droite(t_player *player, char *arg)
{
  (void)player;
  (void)arg;
  printf("droite found\n");
  return (true);
}

bool		player_gauche(t_player *player, char *arg)
{
  (void)player;
  (void)arg;
  printf("gauche found\n");
  return (true);
}

bool		player_prend(t_player *player, char *arg)
{
  (void)player;
  (void)arg;
  printf("prend found\n");
  return (true);
}

bool		player_pose(t_player *player, char *arg)
{
  (void)player;
  (void)arg;
  printf("pose found\n");
  return (true);
}

bool		player_expulse(t_player *player, char *arg)
{
  (void)player;
  (void)arg;
  printf("expulse found\n");
  return (true);
}

bool		player_broadcast(t_player *player, char *arg)
{
  (void)player;
  (void)arg;
  printf("broadcast found\n");
  return (true);
}

bool		player_incantation(t_player *player, char *arg)
{
  (void)player;
  (void)arg;
  printf("incantation found\n");
  return (true);
}

bool		player_fork(t_player *player, char *arg)
{
  (void)player;
  (void)arg;
  printf("fork found\n");
  return (true);
}

bool		player_connect_nbr(t_player *player, char *arg)
{
  (void)player;
  (void)arg;
  printf("connect_nbr found\n");
  return (true);
}

bool		player_inventaire(t_player *player, char *arg)
{
  (void)player;
  (void)arg;
  printf("inventaire found\n");
  return (true);
}

int	handle_input(t_player *player)
{
  char	buffer[4096];
  int	len;

  printf("%s", CLIENT_PROMPT);
  fflush(stdout);
  while ((len = read(0, buffer, 4095)) > 0)
    {
      buffer[len] = 0;
      AI_PI(player, &buffer[0]);
      printf("%s", CLIENT_PROMPT);
      fflush(stdout);
    }
  if (len == -1)
    {
      print_error("read() failed");
      return (-1);
    }
  return (0);
}

int	main(void)
{
  int	fake_player;

  fake_player = 0;
  return (handle_input(&fake_player));
}
