//
// client.hh for ZAPPY_IA in /home/cisner_d/ZAPPY/FINAL_IA
// 
// Made by [D[C[3~[3~[3~
// Login   <cisner_d@epitech.net>
// 
// Started on  Sun Jun  1 11:41:25 2014 [D[C[3~[3~[3~
// Last update Sun Jul 13 16:37:31 2014 [D[C[3~[3~[3~
//

#ifndef		NETWORK_HH_
# define	NETWORK_HH_

# include	<sys/types.h>
# include	<sys/socket.h>
# include	<netdb.h>
# include	<netinet/in.h>
# include	<arpa/inet.h>
# include	<unistd.h>
# include	"exception.hpp"

class		Network
{
  struct sockaddr_in	sin;
  struct protoent	*pe;
  std::string		ip;
  int	port;
  int	fd;

 public:
  Network();
  ~Network();

  void			init(const std::string &ip, int port);
  void			connect_sock();
  int			Select() const;
  void			putmsg(const std::string &msg) const;
  std::string		getmsg(void) const;
  const std::string	&Ip() const;
  int			Port() const;
};

#endif
