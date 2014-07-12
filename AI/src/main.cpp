#include	"drone.hh"

void		usage()
{
  std::cerr << "\E[31;1musage:\E[m" << std::endl
	    <<  "  ./client_IA [options]" << std::endl
	    << std::endl <<  "Options:" << std::endl
	    <<  "-h\tchoose host ip - default 127.0.0.1" << std::endl
	    <<  "-n\tchoose the team - default \"team1\"" << std::endl
	    <<  "-p\tchoose the port - default 4242" << std::endl
	    <<  "--help\tdisplay this usage and exit" << std::endl;
  throw My_Exception("end.");
}

int		main(int ac, char **av)
{
try
  {
    std::vector<std::string>	arg;

    for (int i = 1; i < ac; i++)
      arg.push_back(av[i]);

    Drone	drone(arg);

    drone.Play();

    std::cout << "\E[32;1mWINNER\E[m" << std::endl;
  }
  catch (My_Exception &e)
  {
    std::string msg(e.what());
    if (!msg.empty() && msg.find("error:") != std::string::npos)
      std::cout << "\E[31;1m" << msg << "\E[m" << std::endl;
    else if (!msg.empty())
      std::cerr  << "\E[31;1m" << msg << "\E[m" << std::endl;
    return (2);
  }
  return (0);
}
