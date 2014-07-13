/*
** parse_parameter.h for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Parameters/inc
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 18:56:54 2014 Valentin
** Last update Sun Jul 13 18:56:56 2014 Valentin
*/

#ifndef		PARSE_PARAMETER_H_
# define	PARSE_PARAMETER_H_

# include	"server.h"

typedef void (*func_opt_ptr)(int ac, char **av);

void		parse_param(int ac, char **av);

#endif		/* !PARSE_PARAMETER_H_ */
