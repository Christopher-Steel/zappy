#include	"drone.hh"

void		Drone::init_fct_act()
{
  this->actions[SEE] = &Drone::Receive_See;
  this->actions[INVENTORY] = &Drone::Receive_Inventory;
  this->actions[CAST] = &Drone::Receive_Cast;
  this->actions[SLOTS] = &Drone::Receive_Slots;
  this->actions[FORWARD] = &Drone::Receive_Forward;
  this->actions[LEFT] = &Drone::Receive_Left;
  this->actions[RIGHT] = &Drone::Receive_Right;
  this->actions[TAKE] = &Drone::Receive_Take;
  this->actions[DROP] = &Drone::Receive_Drop;
  this->actions[EXPULSE] = &Drone::Receive_Expulse;
  this->actions[SPEAK] = &Drone::Receive_Speak;
  this->actions[FORK] = &Drone::Receive_Fork;
}

void		Drone::init_fct_dir()
{
  this->directions[0] = &Drone::zero;
  this->directions[1] = &Drone::one;
  this->directions[2] = &Drone::two;
  this->directions[3] = &Drone::three;
  this->directions[4] = &Drone::four;
  this->directions[5] = &Drone::five;
  this->directions[6] = &Drone::six;
  this->directions[7] = &Drone::seven;
  this->directions[8] = &Drone::eight;
}

void		Drone::init_sypher()
{
  this->sypher = "[team:" + this->team.name + "][id:";
  this->sypher += translate<int, std::string>(this->id) + "][id_max:";
  this->sypher += translate<int, std::string>(this->id_max) + "][level:";
  this->sypher += translate<int, std::string>(this->level) + "]";
}

void		Drone::init_client(const std::vector<std::string> &arg)
{
  this->team.name = "team1";
  int port = 4242;
  std::string ip = "127.0.0.1";

  for (std::vector<std::string>::const_iterator it = arg.begin(); it != arg.end(); ++it)
    {
      if (((*it) == "-p") && (it + 1 != arg.end()))
	port = translate<std::string, int>(*(++it));
      else if (((*it) == "-h") && (it + 1 != arg.end()))
	ip = (*(++it));
      else if (((*it) == "-n") && (it + 1 != arg.end()))
	this->team.name = (*(++it));
      else
	usage();
    }
  this->net.init(ip, port);
}

void		Drone::init_obj()
{
  this->obj[FOOD] = "nourriture";
  this->obj[LINEMATE] = "linemate";
  this->obj[DERAUMERE] = "deraumere";
  this->obj[SIBUR] = "sibur";
  this->obj[MENDIANE] = "mendiane";
  this->obj[PHIRAS] = "phiras";
  this->obj[THYSTAME] = "thystame";
  this->obj[DRONE] = "joueur";

  this->inventory[FOOD] = 10;
  this->inventory[LINEMATE] = 0;
  this->inventory[DERAUMERE] = 0;
  this->inventory[SIBUR] = 0;
  this->inventory[MENDIANE] = 0;
  this->inventory[PHIRAS] = 0;
  this->inventory[THYSTAME] = 0;
}

void		Drone::init_map()
{
  this->coor.x = 8;
  this->coor.y = 0;
  this->axis = D_UP;

  for(int y = 0; y < 8; ++y)
    {
      std::vector<std::list<Object> >	v;
      for(int x = 0; x < 16; ++x)
	{
	  std::list<Object> l;
	  v.push_back(l);
	}
      this->map.push_back(v);
    }
}

void		Drone::init_evolve()
{
  this->evolve[ONE][FOOD] = 10;
  this->evolve[ONE][LINEMATE] = 1;
  this->evolve[ONE][DERAUMERE] = 0;
  this->evolve[ONE][SIBUR] = 0;
  this->evolve[ONE][MENDIANE] = 0;
  this->evolve[ONE][PHIRAS] = 0;
  this->evolve[ONE][THYSTAME] = 0;
  this->evolve[ONE][DRONE] = 1;

  this->evolve[TWO][FOOD] = 10;
  this->evolve[TWO][LINEMATE] = 1;
  this->evolve[TWO][DERAUMERE] = 1;
  this->evolve[TWO][SIBUR] = 1;
  this->evolve[TWO][MENDIANE] = 0;
  this->evolve[TWO][PHIRAS] = 0;
  this->evolve[TWO][THYSTAME] = 0;
  this->evolve[TWO][DRONE] = 2;

  this->evolve[THREE][FOOD] = 10;
  this->evolve[THREE][LINEMATE] = 2;
  this->evolve[THREE][DERAUMERE] = 0;
  this->evolve[THREE][SIBUR] = 1;
  this->evolve[THREE][MENDIANE] = 0;
  this->evolve[THREE][PHIRAS] = 2;
  this->evolve[THREE][THYSTAME] = 0;
  this->evolve[THREE][DRONE] = 2;

  this->evolve[FOUR][FOOD] = 10;
  this->evolve[FOUR][LINEMATE] = 1;
  this->evolve[FOUR][DERAUMERE] = 1;
  this->evolve[FOUR][SIBUR] = 2;
  this->evolve[FOUR][MENDIANE] = 0;
  this->evolve[FOUR][PHIRAS] = 1;
  this->evolve[FOUR][THYSTAME] = 0;
  this->evolve[FOUR][DRONE] = 4;

  this->evolve[FIVE][FOOD] = 10;
  this->evolve[FIVE][LINEMATE] = 1;
  this->evolve[FIVE][DERAUMERE] = 2;
  this->evolve[FIVE][SIBUR] = 1;
  this->evolve[FIVE][MENDIANE] = 3;
  this->evolve[FIVE][PHIRAS] = 0;
  this->evolve[FIVE][THYSTAME] = 0;
  this->evolve[FIVE][DRONE] = 4;

  this->evolve[SIX][FOOD] = 10;
  this->evolve[SIX][LINEMATE] = 1;
  this->evolve[SIX][DERAUMERE] = 2;
  this->evolve[SIX][SIBUR] = 3;
  this->evolve[SIX][MENDIANE] = 0;
  this->evolve[SIX][PHIRAS] = 1;
  this->evolve[SIX][THYSTAME] = 0;
  this->evolve[SIX][DRONE] = 6;

  this->evolve[SEVEN][FOOD] = 10;
  this->evolve[SEVEN][LINEMATE] = 2;
  this->evolve[SEVEN][DERAUMERE] = 2;
  this->evolve[SEVEN][SIBUR] = 2;
  this->evolve[SEVEN][MENDIANE] = 2;
  this->evolve[SEVEN][PHIRAS] = 2;
  this->evolve[SEVEN][THYSTAME] = 1;
  this->evolve[SEVEN][DRONE] = 6;

  this->evolve[MAX][FOOD] = 30;
  this->evolve[MAX][LINEMATE] = 9;
  this->evolve[MAX][DERAUMERE] = 8;
  this->evolve[MAX][SIBUR] = 10;
  this->evolve[MAX][MENDIANE] = 5;
  this->evolve[MAX][PHIRAS] = 6;
  this->evolve[MAX][THYSTAME] = 1;
  this->evolve[MAX][DRONE] = 6;
}
