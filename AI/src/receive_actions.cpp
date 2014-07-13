#include	"drone.hh"
#include	<stdlib.h>

void		Drone::Receive_Forward(const std::string &str)
{
  this->rep.pop_front();
  if (str.empty())
    return;
}

void		Drone::Receive_Left(const std::string &str)
{
  this->rep.pop_front();
  if (str.empty())
    return;
}

void		Drone::Receive_Right(const std::string &str)
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

void		Drone::Push_map(int x, int y, const std::string &str)
{
  std::string	tmp = str;

  while (tmp.find(" ") != std::string::npos)
    {
      std::string	sub;

      tmp = tmp.substr(tmp.find(" ") + 1);
      if (tmp.find(" ") != std::string::npos)
	sub = tmp.substr(0, tmp.find(" "));
      else
	sub = tmp;
      for (int i = FOOD; i <= DRONE; ++i)
	if (sub.find(this->obj[(Object)i]) != std::string::npos)
	  this->map[y][x].push_back((Object)i);
    }
}

void		Drone::Receive_See(const std::string &str)
{
  int		x = 8;
  int		y = 0;
  int		len = 0;
  int		len_max = 1;
  std::string	tmp = str;
  std::string	sub;

  this->rep.pop_front();
  this->clear_map();

  while(tmp.find(",") != std::string::npos)
    {
      sub = tmp.substr(0, tmp.find(","));

      this->Push_map(x, y, sub);
      tmp = tmp.substr(tmp.find(",") + 1);
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
  this->Push_map(x, y, tmp);

  this->coor.x = 8;
  this->coor.y = 0;
  this->axis = D_UP;
  this->is_see = false;
}

void		Drone::Receive_Inventory(const std::string &str)
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

void		Drone::Receive_Take(const std::string &str)
{
  this->rep.pop_front();
  if (str.empty())
    return;
}

void		Drone::Receive_Drop(const std::string &str)
{
  this->rep.pop_front();
  if (str.empty())
    return;
}

void		Drone::Receive_Expulse(const std::string &str)
{
  this->rep.pop_front();
  if (str.empty())
    return;
}

void		Drone::Receive_Speak(const std::string &str)
{
  this->rep.pop_front();
  if (str.empty())
    return;
}

void		Drone::Receive_Cast(const std::string &str)
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
      while (this->is_cast != false)
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
	  if (this->id > SIX && this->level > FIVE)
	    this->duty = OTHER;
	  else if (this->id % this->evolve[this->level][DRONE] == 0)
	    this->duty = CASTER;
	  else
	    this->duty = FOLLOWER;
	  this->init_sypher();
	  if (level == ONE && this->id < 7)
	    this->Send_Fork();
	}
      this->is_cast = false;
    }
  else if (str == "ko" && (this->duty == CASTER || this->duty == NONE))
    {
      this->rep.pop_front();
      if (this->duty == CASTER)
	this->Send_Speak("[level up ko].");
      this->is_cast = false;
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
  this->is_fork = false;
}

void		Drone::Receive_Fork(const std::string &str)
{
  this->rep.pop_front();
  if (str == "ok")
    return;
}

void		Drone::Receive_Slots(const std::string &str)
{
  this->rep.pop_front();
  this->team.slots = translate<std::string, int>(str);
}
