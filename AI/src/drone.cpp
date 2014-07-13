#include	"drone.hh"

Drone::Drone(const std::vector<std::string> &arg)
{
  this->init_client(arg);
  this->init_fct_act();
  this->init_fct_dir();
  this->init_obj();
  this->init_map();
  this->init_evolve();
  this->is_see = false;
  this->is_fork = false;
  this->is_cast = false;
  this->is_action = false;
  this->id = 0;
  this->id_max = 0;
  this->duty = NONE;

  this->Hello();

  this->level = ONE;
  this->init_sypher();
  this->Send_Speak("do you have an id?");
}

Drone::~Drone() {}

void		Drone::Check_msg(const std::string &str)
{
  if (str.find("[team:") == std::string::npos
      || str.find("[id:") == std::string::npos
      || str.find("[id_max:") == std::string::npos
      || str.find("[level:") == std::string::npos)
    return;
  int		id;
  int		id_m;
  int		level;
  std::string	team;

  team = str.substr(str.find("[team:") + strlen("[team:"));
  team = team.substr(0, team.find("]"));
  id = translate<std::string, int>(str.substr(str.find("[id:") + strlen("[id:")));
  id_m = translate<std::string, int>(str.substr(str.find("[id_max:") + strlen("[id_max:")));
  level = translate<std::string, int>(str.substr(str.find("[level:") + strlen("[level:")));

  if (team != this->team.name)
    return;
  if (str.find("i have this id.") != std::string::npos && this->id <= id_m)
    {
      this->id_max = id_m + 1;
      if (duty == NONE)
	  this->id = this->id_max;
      this->init_sypher();
    }
  else if (str.find("do you have an id?") != std::string::npos && this->duty != NONE)
    {
      if (!(this->is_cast == true && this->duty == CASTER))
	this->Send_Speak("i have this id.");
    }
  else if (id == this->id - (this->id % this->evolve[this->level][DRONE])
	   && str.find("[level up") != std::string::npos && level == this->level
	   && this->duty == FOLLOWER)
    {
      std::list<std::string>::iterator it;

      for (it = this->msg.begin(); it != this->msg.end()
	     && (*it).find("[level up]") == std::string::npos; ++it);
      if (it != this->msg.end())
	this->msg.erase(it);
      this->msg.push_back(str);
    }
}

void		Drone::Recive()
{
  std::string	str = this->net.getmsg();
  std::string	tmp;
  unsigned int	pos;

  while (str.find("\n") != std::string::npos && this->level != MAX)
    {
      pos = str.find("\n");
      tmp = str.substr(0, pos);

      if (tmp.find("message") == 0)
	Check_msg(tmp);
      else if (tmp.find("deplacement") == 0)
	{}
      else if (tmp.find("mort") == 0)
	throw My_Exception("Sorry you are dead.");
      else if (!this->rep.empty())
	(this->*actions[this->rep.front()])(tmp);
      str = str.substr(pos + 1);
    }
}

void		Drone::Hello()
{
  std::string   tmp = this->net.getmsg();
  this->net.putmsg(this->team.name + "\n");
  tmp = this->net.getmsg();
  if (tmp == "NO SUCH TEAM\n")
    throw My_Exception("Drone: error: no such team.");
  else if (tmp.find("ko") != std::string::npos)
    throw My_Exception("Drone: error: can't connect in this team.");
  this->team.slots = translate<std::string, int>(tmp);
  if (tmp.find("\n") + 1 == tmp.size())
    this->net.getmsg();
}

void		Drone::clear_rep()
{
  while (!this->rep.empty())
    this->Recive();
}

void		Drone::Send(const Action &act, const std::string &str)
{
  if (this->rep.size() == 10)
    this->clear_rep();
  this->rep.push_back(act);
  this->net.putmsg(str + "\n");
}

void		Drone::Play()
{
  while (this->level != MAX)
    {
      if (this->is_fork == true)
	{
	  if (this->team.slots == 0)
	    this->Send_Slots();
	  else
	    this->do_fork();
	}
      if (this->net.Select())
      	this->Recive();

      this->Send_Inventory();
      this->Send_See();
      this->Algorithm();
    }
}
