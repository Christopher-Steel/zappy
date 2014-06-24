#include "world.h"

void	show_inventory(t_player *player, char *res)
{
  (void)res;
  printf("Inventory player :\nFOOD = %d\nLINEMATE = %d\nDERAUMERE = %d\nSIBUR = %d\nMENDIANE = %d\nPHIRAS = %d\nTHYSTAME = %d\n",
	 player->inventory[FOOD],
	 player->inventory[LINEMATE],
	 player->inventory[DERAUMERE],
	 player->inventory[SIBUR],
	 player->inventory[MENDIANE],
	 player->inventory[PHIRAS],
	 player->inventory[THYSTAME]);
}
