#include	"drone.hh"
#include	<string.h>

void		Drone::Send_Forward()
{
  if (this->axis == D_UP)
    ++this->coor.y;
  else if (this->axis == D_LEFT)
    --this->coor.x;
  else if (this->axis == D_DOWN)
    --this->coor.y;
  else if (this->axis == D_RIGHT)
    ++this->coor.x;

  this->Send(FORWARD, "avance");
  if (this->inventory[FOOD] < this->evolve[this->level][FOOD])
    {
      std::list<Object>	tmp = this->map[this->coor.y][this->coor.x];

      for (std::list<Object>::iterator it = tmp.begin(); it != tmp.end(); ++it)
	{
	  if ((*it) == FOOD)
	    this->Send_Take(this->obj[FOOD]);
	}
    }
}

void		Drone::Send_Left()
{
  if (this->axis == D_UP)
    this->axis = D_LEFT;
  else if (this->axis == D_LEFT)
    this->axis = D_DOWN;
  else if (this->axis == D_DOWN)
    this->axis = D_RIGHT;
  else if (this->axis == D_RIGHT)
    this->axis = D_UP;

  this->Send(LEFT, "gauche");
}

void		Drone::Send_Right()
{
  if (this->axis == D_UP)
    this->axis = D_RIGHT;
  else if (this->axis == D_LEFT)
    this->axis = D_UP;
  else if (this->axis == D_DOWN)
    this->axis = D_LEFT;
  else if (this->axis == D_RIGHT)
    this->axis = D_DOWN;

  this->Send(RIGHT, "droite");
}

void		Drone::Send_See()
{
  this->is_action = true;
  this->Send(SEE, "voir");
  while (this->is_action != false)
    this->Recive();
}

void		Drone::Send_Inventory()
{
  this->Send(INVENTORY, "inventaire");
}

void		Drone::Send_Take(std::string str)
{
  int		i;

  this->Send(TAKE, "prend " + str);
  for (i = FOOD; this->obj[(Object) i] != str && i < DRONE; ++i);
  if (i != DRONE)
    ++this->inventory[(Object) i];
}

void		Drone::Send_Drop(std::string str)
{
  int		i;

  this->Send(DROP, "pose " + str);
  for (i = FOOD; this->obj[(Object) i] != str && i < DRONE; ++i);
  if (i != DRONE)
   -- this->inventory[(Object) i];
}

void		Drone::Send_Expulse()
{
  this->Send(EXPULSE, "expulse");
}

void		Drone::Send_Speak(std::string str)
{
  this->Send(SPEAK, "broadcast " + sypher + str);
}

void		Drone::Send_Cast()
{
  this->is_action = true;
  this->Send(CAST, "incantation");
  while (this->is_action != false)
    this->Recive();
}

void		Drone::Send_Fork()
{
  this->is_action = true;
  this->Send(FORK, "fork");
  while (this->is_action != false)
    this->Recive();
}

void		Drone::Send_Slots()
{
  this->is_action = true;
  this->Send(SLOTS, "connect_nbr");
  while (this->is_action != false)
    this->Recive();
}
