#include	"drone.hh"
#include	<stdlib.h>

void		Drone::Recive_Forward(std::string str)
{
  this->rep.pop_front();
  if (str.empty())
    return;
}

void		Drone::Recive_Left(std::string str)
{
  this->rep.pop_front();
  if (str.empty())
    return;
}

void		Drone::Recive_Right(std::string str)
{
  this->rep.pop_front();
  if (str.empty())
    return;
}

void		Drone::clear_map()
{
  for (int y = 0; y < 8; ++y)
    for (int x = 0; x < 16; ++x)
      this->map[y][x].clear();
}

void		Drone::Push_map(int x, int y, std::string str)
{
  while (str.find(" ") != std::string::npos)
    {
      std::string	tmp;

      str = str.substr(str.find(" ") + 1);
      if (str.find(" ") != std::string::npos)
	tmp = str.substr(0, str.find(" "));
      else
	tmp = str;
      for (int i = FOOD; i <= DRONE; ++i)
	if (tmp.find(this->obj[(Object)i]) != std::string::npos)
	  this->map[y][x].push_back((Object)i);
    }
}

void		Drone::Recive_See(std::string str)
{
  int	x = 8;
  int	y = 0;
  int	len = 0;
  int	len_max = 1;

  this->rep.pop_front();
  this->clear_map();
  while(str.find(",") != std::string::npos)
    {
      std::string	tmp = str.substr(0, str.find(","));

      this->Push_map(x, y, tmp);
      str = str.substr(str.find(",") + 1);
      ++len;
      ++x;
      if (len == len_max)
	{
	  len_max += 2;
	  ++y;
	  x = 8 - y;
	  len = 0;
	}
    }
  std::string	tmp = str.substr(0, str.find(","));
  for (int i = FOOD; i <= DRONE; ++i)
    if (tmp.find(this->obj[(Object)i]) != std::string::npos)
      this->map[y][x].push_back((Object)i);

  this->coor.x = 8;
  this->coor.y = 0;
  this->axis = D_UP;
  this->is_action = false;
}

void		Drone::Recive_Inventory(std::string str)
{
  this->rep.pop_front();
  for (int i = 0; i < DRONE; ++i)
    {
      unsigned int	pos = str.find(this->obj[(Object)i]);

      if (str.find(this->obj[(Object)i]) != std::string::npos)
	{
	  std::string	tmp = str.substr(pos + this->obj[(Object)i].size() + 1);
	  this->inventory[i] = translate<std::string, int>(tmp);
	}
    }
}

void		Drone::Recive_Take(std::string str)
{
  this->rep.pop_front();
  if (str.empty())
    return;
}

void		Drone::Recive_Drop(std::string str)
{
  this->rep.pop_front();
  if (str.empty())
    return;
}

void		Drone::Recive_Expulse(std::string str)
{
  this->rep.pop_front();
  if (str.empty())
    return;
}

void		Drone::Recive_Speak(std::string str)
{
  this->rep.pop_front();
  if (str.empty())
    return;
}

void		Drone::Recive_Cast(std::string str)
{
  if (str == "ok")
    {
      std::list<Action>::iterator it;

      for (it = this->rep.begin(); it != this->rep.end()
	     && (*it) != SPEAK; ++it);
      if ((*it) == SPEAK)
	this->rep.erase(it);
    }
  if (str == "elevation en cours")
    {
      this->rep.pop_front();
      this->rep.push_back(CAST);
      while (this->is_action != false)
	this->Recive();
    }
  else if (str.find("niveau actuel : ") == 0)
    {
      this->rep.pop_front();
      std::string	tmp = str.substr(strlen("niveau actuel : "));
      Level		level = this->level;

      this->level = (Level)(translate<std::string, int>(tmp) - 1);
      if (this->level != level)
	{
	  if (this->id > 6 && this->level > 5)
	    this->duty = OTHER;
	  else if (this->id % this->evolve[this->level][DRONE] == 0)
	    this->duty = CASTER;
	  else
	    this->duty = FOLLOWER;
	  this->init_sypher();
	  if (level == ONE && this->id < 7)
	    this->Send_Fork();
	}
      this->is_action = false;
    }
  else if (this->duty == CASTER || this->duty == NONE)
    {
      this->rep.pop_front();
      if (this->duty == CASTER)
	this->Send_Speak("[level up ko].");
      this->is_action = false;
    }
}

void		Drone::do_fork()
{
  int		pid = fork();

  if (pid == -1)
    throw My_Exception("Drone: error: can't fork.");
  else if (pid == 0)
    {
      std::string	cmd = "./zappy_AI -h ";

      std::cout << "in" << std::endl;
 
      cmd += this->net.Ip();
      cmd += " -p ";
      cmd += translate<int, std::string>(this->net.Port());
      cmd += " -n ";
      cmd += this->team.name;
      cmd += " > error";
      cmd += translate<int, std::string>(this->id + 1);
      cmd += "\n";

      int	ret = system(cmd.c_str());

      if (ret == -1)
	throw My_Exception("Drone: error: execv fail.");
      throw My_Exception("");
    }
}

void		Drone::Recive_Fork(std::string str)
{
  this->rep.pop_front();
  if (str == "ok")
    {
      while (this->team.slots == 0)
      	this->Send_Slots();
      this->do_fork();
    }
  this->is_action = false;
}

void		Drone::Recive_Slots(std::string str)
{
  this->rep.pop_front();
  this->team.slots = translate<std::string, int>(str);
  this->is_action = false;
}
