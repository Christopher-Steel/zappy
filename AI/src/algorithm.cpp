#include	"drone.hh"

void		Drone::Algorithm()
{
  if (this->inventory[FOOD] < this->evolve[this->level][FOOD])
    {
      this->evolve[this->level][FOOD] = 20;
      this->Search_obj(FOOD);
    }
  else
    {
      this->evolve[this->level][FOOD] = 10;
      if (!this->msg.empty())
	this->andle_msg();

      if (this->duty == NONE || this->duty == CASTER)
	{
	  std::list<Object>	tmp = this->map[this->coor.y][this->coor.x];
	  int		nb_drone = 0;
	  int		i = 0;
      
	  for(std::list<Object>::iterator it = tmp.begin(); it != tmp.end(); ++it)
	    {
	      if (*it == DRONE)
		nb_drone++;
	    }
	  while (i < DRONE && this->inventory[i] >= this->evolve[this->level][(Object)i])
	    ++i;
	  if (i != DRONE)
	    Search_obj((Object)i);
	  else if (nb_drone < this->evolve[this->level][DRONE])
	    this->Send_Speak("[level up] help.");
	  else
	    this->prepare_cast();
	}
    }
}

void		Drone::clear_case()
{
  std::list<Object>	tmp = this->map[this->coor.y][this->coor.x];

  for(std::list<Object>::iterator it = tmp.begin(); it != tmp.end(); ++it)
    {
      if (*it != DRONE)
	this->Send_Take(this->obj[*it]);
    }
}

void		Drone::prepare_cast()
{
  if (this->duty == CASTER)
    this->Send_Speak("[level up] begin.");
  this->clear_case();
  for(int res = LINEMATE; res < DRONE; ++res)
    {
      for(int i = this->evolve[this->level][(Object)res]; i > 0; --i)
	this->Send_Drop(this->obj[(Object)res]);
    }
  this->Send_Cast();
}


void		Drone::Search_obj(Object obj)
{
  std::list<Object>::iterator	it;
  std::list<Object>		tmp = this->map[this->coor.y][this->coor.x];
  bool				find = false;

  for (it = tmp.begin(); it != tmp.end() && (*it) != obj; ++it);
  if ((*it) == obj)
    find = true;
  for (int y = 0; y < 8 && find != true; ++y)
    {
      for (int x = 0; x < 16 && find != true; ++x)
	{
	  tmp = this->map[y][x];
	  for (it = tmp.begin(); it != tmp.end() && (*it) != obj; ++it);
	  if ((*it) == obj)
	    {
	      this->to_case(y, x);
	      find = true;
	    }
	}
    }
  if (find == true)
    this->Send_Take(this->obj[obj]);
  else
    this->hang_around();
}

void		Drone::to_case(int y, int x)
{
  while (this->coor.y != y)
    this->Send_Forward();

  if (this->coor.x < x)
    this->Send_Right();
  else if (this->coor.x > x)
    this->Send_Left();
  while (this->coor.x != x)
    this->Send_Forward();
}

void		Drone::hang_around()
{
  this->Send_Forward();
}
