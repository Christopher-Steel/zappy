#include <stdlib.h>
#include <string.h>

#include "AI_PI.h"
#include "print_debug.h"
#include "print_error.h"

static t_AI_cmd	g_cmds[] =
  {
    AI_CMD(voir, false, 7.0),
    AI_CMD(avance, false, 7.0),
    AI_CMD(droite, false, 7.0),
    AI_CMD(gauche, false, 7.0),
    AI_CMD(prend, true, 7.0),
    AI_CMD(pose, true, 7.0),
    AI_CMD(expulse, false, 7.0),
    AI_CMD(broadcast, true, 7.0),
    AI_CMD(incantation, false, 0.0),
    AI_CMD(fork, false, 0.0),
    AI_CMD(connect_nbr, false, 0.0),
    AI_CMD(inventaire, false, 1.0)
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
  for (i = 0; i < cmd_size && strcmp(g_cmds[i].name, token); ++i);
  free(backup_str);
  return ((i < cmd_size ? (int)i : -1));
}

t_pl_func	AI_PI(char **cmd, double *delay)
{
  char	*args;
  int	cmd_id;

  printf_debug("Parsing command: %s", *cmd);
  if ((cmd_id = get_cmd_id(*cmd)) == -1)
    {
      printf_error("%s: command not found", *cmd);
      return (NULL);
    }
  args = *cmd + strlen(g_cmds[cmd_id].name);
  while (*args != '\0' && (*args == ' ' || *args == '\t' || *args == '\n'))
    ++args;
  if ((*args != '\0' && *args != '\n') != (g_cmds[cmd_id].hasArg))
    {
      printf_error("%s: invalid arguments", *cmd);
      return (NULL);
    }
  *cmd = (*args != '\0' ? args : NULL);
  *delay = g_cmds[cmd_id].delay;
  return (g_cmds[cmd_id].fn);
}
