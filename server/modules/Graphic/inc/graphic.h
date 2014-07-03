#ifndef		GRAPHIC_H_
# define	GRAPHIC_H_

# include	"network_client.h"
# include	"receiver.h"

typedef struct	s_graphic
{
  void		(*receive)(t_receiver *rec, char *msg);
  void		(*destroy)(t_receiver *rec);
  t_client	*client;
}		t_graphic;

t_graphic	*graphic_create(t_client *client);

#endif		/* GRAPHIC_H_ */
