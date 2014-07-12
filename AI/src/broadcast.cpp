#include	"drone.hh"

void		Drone::andle_msg()
{
  while (!this->msg.empty())
    {
      std::string	tmp;
       int		dir;

      tmp = this->msg.front();
      dir = translate<std::string, int>(tmp.substr(tmp.find(" ") + 1));
 
      if (tmp.find("[level up] help.") != std::string::npos)
	(this->*directions[dir])();
      else if (tmp.find("[level up] begin.") != std::string::npos)
	this->level_up();
      else if (tmp.find("[level up ko].") != std::string::npos)
	{
	  std::list<Action>::iterator it;

	  for (it = this->rep.begin(); it != this->rep.end()
		 && (*it) != CAST; ++it);
	  if ((*it) == CAST)
	    this->rep.erase(it);

	  if (this->rep.front() == CAST)
	    this->rep.pop_front();
	  this->is_cast = false;
	}
      if (!this->msg.empty())
	this->msg.pop_front();
    }
}

void		Drone::level_up()
{
  this->msg.pop_front();
  this->is_cast = true;
  this->rep.push_back(CAST);
  while (this->is_cast != false)
    {
      this->Recive();
      if (!this->msg.empty())
	this->andle_msg();
    }
}

void		Drone::zero()
{}

void		Drone::one()
{
  this->Send_Forward();
}

void		Drone::two()
{
  this->Send_Forward();
  this->Send_Left();
  this->Send_Forward();
}

void		Drone::three()
{
  this->Send_Left();
  this->Send_Forward();
}

void		Drone::four()
{
  this->Send_Left();
  this->Send_Forward();
  this->Send_Left();
  this->Send_Forward();
}

void		Drone::five()
{
  this->Send_Left();
  this->Send_Left();
  this->Send_Forward();
}

void		Drone::six()
{
  this->Send_Right();
  this->Send_Forward();
  this->Send_Right();
  this->Send_Forward();
}

void		Drone::seven()
{
  this->Send_Right();
  this->Send_Forward();
}

void		Drone::eight()
{
  this->Send_Forward();
  this->Send_Right();
  this->Send_Forward();
}
