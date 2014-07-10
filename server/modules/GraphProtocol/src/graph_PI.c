
#include <string.h>

#include "graph_PI.h"
#include "network_client.h"
#include "print_error.h"

static t_graph_cmd g_cmds[] =
  {
    GRAPH_CMD(msz, false),
    GRAPH_CMD(bct, true),
    GRAPH_CMD(mct, false)/*,
    GRAPH_CMD(tna, false),
    GRAPH_CMD(ppo, true),
    GRAPH_CMD(plv, true),
    GRAPH_CMD(pin, true),
    GRAPH_CMD(sgt, false),
    GRAPH_CMD(sst, true)*/
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

bool	graph_PI(t_graphic *graphic, char *cmd)
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
  return (g_cmds[cmd_id].fn(graphic, (*args != '\0' ? args : NULL)));
}

bool	graph_send_to(t_graphic *graphic, char *cmd)
{
  if (client_write_to(graphic->client, cmd))
    {
      free(cmd);
      return (true);
    }
  free(cmd);
  return (false);
}
