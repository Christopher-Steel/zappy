//
// drone.hh for ZAPPY_IA in /home/cisner_d/ZAPPY/FINAL_IA
// 
// Made by [D[C[3~[3~[3~
// Login   <cisner_d@epitech.net>
// 
// Started on  Sun Jun  1 10:50:50 2014 [D[C[3~[3~[3~
// Last update Sun Jul 13 17:59:05 2014 [D[C[3~[3~[3~
//

#ifndef		DRONE_HH_
# define	DRONE_HH_

# include	<string.h>
# include	<sstream>
# include	<vector>
# include	<list>
# include	<map>
# include	<time.h>
# include	"network.hh"

enum	Duty
  {
    NONE,
    CASTER,
    FOLLOWER,
    OTHER
  };

enum	Action
  {
    SEE,
    INVENTORY,
    CAST,
    SLOTS,
    FORWARD,
    LEFT,
    RIGHT,
    TAKE,
    DROP,
    EXPULSE,
    SPEAK,
    FORK
  };

enum	Object
  {
    FOOD,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
    DRONE
  };

enum	Level
  {
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    MAX
  };

enum	Direction
  {
    D_UP,
    D_DOWN,
    D_LEFT,
    D_RIGHT
  };

struct		Vector
{
  int		x;
  int		y;
};

struct		Team
{
  std::string	name;
  int		slots;
};

void		usage();

template<typename T, typename U>
U		translate(const T &ori)
{
  U	tmp;
  U	ret;
  std::stringstream ss (std::stringstream::in | std::stringstream::out);
  ss << ori;
  ss >> tmp;
  ret = tmp;
  return(ret);
}

class		Drone
{
  typedef void (Drone::*fct_dir)();
  typedef void (Drone::*fct_act)(std::string);

  Network	net;
  Vector	coor;
  Team		team;
  Level		level;
  Direction	axis;
  int		id;
  int		id_max;
  Duty		duty;
  std::string	sypher;
  bool		is_see;
  bool		is_cast;
  bool		is_fork;
  bool		is_action;
  int		inventory[DRONE];
  int		evolve[8][8];

  std::list<Action>		rep;
  std::list<std::string>	msg;
  std::map<Action, fct_act>	actions;
  std::map<int, fct_dir>	directions;
  std::map<Object, std::string>	obj;

  std::vector<std::vector<std::list<Object> > > map;

public:
  Drone(const std::vector<std::string> &arg);
  ~Drone();

  void		Check_msg(const std::string &);
  void		Recive();
  void		clear_rep();
  void		Send(const Action &, const std::string &);
  void		Hello();
  void		Play();

/****************************************\
**					**
**		BROADCAST	       	**
**					**
\****************************************/

  void		andle_msg();
  void		level_up();
  void		zero();
  void		one();
  void		two();
  void		three();
  void		four();
  void		five();
  void		six();
  void		seven();
  void		eight();

/****************************************\
**					**
**		INITS			**
**					**
\****************************************/

  void		clear_map();
  void		init_obj();
  void		init_map();
  void		init_sypher();
  void		init_evolve();
  void		init_fct_act();
  void		init_fct_dir();
  void		init_client(const std::vector<std::string> &arg);

/****************************************\
**					**
**	       AGORITHM			**
**					**
\****************************************/

  void		Algorithm();
  void		clear_case();
  void		prepare_cast();
  void		Search_obj(const Object &obj);
  void		to_case(int y, int x);
  void		hang_around();

/****************************************\
**					**
**		ACTIONS			**
**					**
\****************************************/

  void		Push_map(int x, int y, std::string str);
  void		do_fork();

  void		Send_Forward();
  void		Send_Right();
  void		Send_Left();
  void		Send_See();
  void		Send_Inventory();
  void		Send_Take(const std::string &);
  void		Send_Drop(const std::string &);
  void		Send_Expulse();
  void		Send_Speak(const std::string &);
  void		Send_Cast();
  void		Send_Fork();
  void		Send_Slots();

  void		Receive_Forward(std::string);
  void		Receive_Right(std::string);
  void		Receive_Left(std::string);
  void		Receive_See(std::string);
  void		Receive_Inventory(std::string );
  void		Receive_Take(std::string);
  void		Receive_Drop(std::string);
  void		Receive_Expulse(std::string);
  void		Receive_Speak(std::string);
  void		Receive_Cast(std::string);
  void		Receive_Fork(std::string);
  void		Receive_Slots(std::string);
};

#endif
