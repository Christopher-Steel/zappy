#ifndef		RECEIVER_H_
# define	RECEIVER_H_

typedef struct	s_receiver
{
  void		(*receive)(struct s_receiver *rec, char *msg);
  void		(*destroy)(struct s_receiver *rec);
}		t_receiver;

#endif		/* RECEIVER_H_ */
