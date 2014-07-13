/*
** AI_PI.h for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/AIProtocol/inc
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 18:19:02 2014 Valentin
** Last update Sun Jul 13 18:19:18 2014 Valentin
*/

#ifndef		AI_PI_H_
# define	AI_PI_H_

# include	"player.h"
# include	"zappy_types.h"

# define	AI_CMD(NAME, ARG, T)	{#NAME, player_ ## NAME, ARG, T}

typedef struct	s_AI_cmd
{
  char		*name;
  bool		(*fn)(void *, void *);
  bool		hasArg;
  double	delay;
}		t_AI_cmd;

t_pl_func	AI_PI(char **cmd, double *delay);

#endif		/* AI_PI_H_ */
