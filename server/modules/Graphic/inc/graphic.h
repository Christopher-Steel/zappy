#ifndef		GRAPHIC_H_
# define	GRAPHIC_H_

# include	"list.h"
# include	"network_client.h"
# include	"player.h"
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

bool		graphic_suc(t_graphic *);
bool		graphic_sbp(t_graphic *);

bool		graphic_pnw(t_graphic *graphic, t_player *player);

bool		graphic_pex(t_graphic *graphic, t_player *player);
bool		graphic_pbc(t_graphic *graphic, t_player *player, char *msg);
bool		graphic_pic(t_graphic *graphic, t_player **players);
bool		graphic_pie(t_graphic *graphic, t_vector *pos, int result);
bool		graphic_pdi(t_graphic *graphic, t_player *player);

bool		graphic_pfk(t_graphic *graphic, t_player *player);
bool		graphic_enw(t_graphic *graphic, t_player *player, t_egg *egg);
bool		graphic_eht(t_graphic *graphic, t_egg *egg);
bool		graphic_ebo(t_graphic *graphic, t_egg *egg);
bool		graphic_edi(t_graphic *graphic, t_egg *egg);

bool		graphic_pdr(t_graphic *graphic, t_player *player, uint obj);
bool		graphic_pgt(t_graphic *graphic, t_player *player, uint obj);

bool		graphic_seg(t_graphic *graphic, char *team_name);
bool		graphic_smg(t_graphic *graphic, char *msg);
bool		graphic_smg_KO(t_graphic *graphic);

#endif		/* GRAPHIC_H_ */
