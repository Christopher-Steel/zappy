#include <stdlib.h>
#include <string.h>

#include "AI_PI.h"
#include "network_client.h"
#include "print_error.h"

static t_AI_cmd	g_cmds[] =
  {
    AI_CMD(voir, false),
    AI_CMD(avance, false),
    AI_CMD(droite, false),
    AI_CMD(gauche, false),
    AI_CMD(prend, true),
    AI_CMD(pose, true),
    AI_CMD(expulse, false),
    AI_CMD(broadcast, true),
    AI_CMD(incantation, false),
    AI_CMD(fork, false),
    AI_CMD(connect_nbr, false),
    AI_CMD(inventaire, false)
  };

static int	get_cmd_id(char *cmd)
{
  static uint	cmd_size = sizeof(g_cmds) / sizeof(*g_cmds);
  char		*backup_str;
  char		*token;
  uint		i;

  backup_str = strdup(cmd);
  if ((token = strtok(backup_str, " \t\n")) == NULL)
    return (-1);
  for (i = 0; i < cmd_size; ++i)
    if (strcmp(g_cmds[i].name, token) == 0)
      break ;
  free(backup_str);
  return ((i < cmd_size ? (int)i : -1));
}

bool	AI_PI(t_player *player, char *cmd)
{
  char	*args;
  int	cmd_id;

  if ((cmd_id = get_cmd_id(cmd)) == -1)
    return (printf_error("%s: command not found", cmd));
  args = cmd + strlen(g_cmds[cmd_id].name);
  while (*args != '\0'
	 && (*args == ' '
	     || *args == '\t'
	     || *args == '\n'))
    ++args;
  if ((*args != '\0' && *args != '\n') != (g_cmds[cmd_id].hasArg))
    return (printf_error("%s: invalid arguments", cmd));
  return (g_cmds[cmd_id].fn(player, (*args != '\0' ? args : NULL)));
}
