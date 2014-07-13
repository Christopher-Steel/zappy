/*
** vector.h for Server in /home/mougen_v/rendus/PSU_2013_zappy/server/modules/Vector/inc
**
** Made by Valentin
** Login   <mougen_v@epitech.net>
**
** Started on  Sun Jul 13 19:15:20 2014 Valentin
** Last update Sun Jul 13 19:15:33 2014 Valentin
*/

#ifndef		VECTOR_H_
# define	VECTOR_H_

/*
** INCLUDE
*/
# include	<stdbool.h>

/*
** STRUCTURE
*/
typedef struct	s_vector
{
  int	x;
  int	y;
}		t_vector;

/*
** PROTOTYPE
*/
t_vector	sub_vector(t_vector vec1, t_vector vec2);
t_vector	add_vector(t_vector vec1, t_vector vec2);
bool		equal_vector(t_vector vec1, t_vector vec2);

#endif		/* !VECTOR_H_ */
