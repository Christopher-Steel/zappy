#ifndef		VECTOR_H_
# define	VECTOR_H_

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

#endif		/* !VECTOR_H_ */
