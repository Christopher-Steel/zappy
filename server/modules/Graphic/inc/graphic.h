#ifndef		GRAPHIC_H_
# define	GRAPHIC_H_

# include	"list.h"
# include	"network_client.h"
# include	"receiver.h"
# include	"zappy_types.h"

typedef struct	s_graphic_manager
{
  t_list	graphic_handlers;
}		t_graphic_manager;

void		graphic_manager_init(void);
void		graphic_manager_shutdown(void);

typedef struct	s_graphic
{
  void		(*receive)(t_receiver *rec, char *msg);
  void		(*destroy)(t_receiver *rec);
  t_client	*client;
}		t_graphic;

t_graphic	*graphic_create(t_client *client);

bool		graphic_msz(t_graphic *, char *);
bool		graphic_bct(t_graphic *, char *);
bool		graphic_mct(t_graphic *, char *);
bool		graphic_tna(t_graphic *, char *);
bool		graphic_ppo(t_graphic *, char *);
bool		graphic_plv(t_graphic *, char *);
bool		graphic_pin(t_graphic *, char *);
bool		graphic_sgt(t_graphic *, char *);
bool		graphic_sst(t_graphic *, char *);

#endif		/* GRAPHIC_H_ */
