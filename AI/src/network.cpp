#include	"network.hh"

Network::Network()
{
  this->port = 4242;
  this->ip = "127.0.0.1";
}

Network::~Network() {}

void		Network::init(const std::string &ip, int port)
{
  this->port = port;
  this->ip = ip;
  this->connect_sock();
}

void		Network::connect_sock()
{
  this->pe = getprotobyname("TCP");
  if (!this->pe)
    throw My_Exception("Network: error: getprotobyname fail.");
  this->fd = socket(AF_INET, SOCK_STREAM, this->pe->p_proto);
  if (this->fd == -1)
    throw My_Exception("Network: error: socket fail.");
  this->sin.sin_family = AF_INET;
  this->sin.sin_port = htons(this->port);
  this->sin.sin_addr.s_addr = inet_addr(this->ip.c_str());
  if (connect(this->fd, (struct sockaddr *)&this->sin,
	      sizeof(this->sin)) == -1)
    {
      if (close(this->fd) == -1)
	throw My_Exception("Network: error: connect error, can't close fd.");
      throw My_Exception("Network: error: connect error.");
    }
}

int		Network::Select() const
{
  fd_set        fd_read;
  struct timeval        tv;
  int                   ret;

  tv.tv_sec = 0;
  tv.tv_usec = 0;
  ret = 0;
  FD_ZERO(&fd_read);
  FD_SET(this->fd, &fd_read);
  if (select(this->fd + 1, &fd_read, NULL, NULL, &tv) == -1)
    throw My_Exception("Network: error: can't use select.");
  if (FD_ISSET(this->fd, &fd_read))
    ret = 1;
  return (ret);
}

void		Network::putmsg(const std::string &msg) const
{
  std::string	tmp;
  int		ret;

  tmp = msg;
  while (!tmp.empty())
    {
      if ((ret = send(this->fd, tmp.c_str(), tmp.size(), 0)) == -1)
	throw My_Exception("Network: error: can't send message.");
      tmp = tmp.substr(ret);
    }
  std::cout << "\E[33;1mClient: " << msg << "\E[m";
}

std::string	Network::getmsg(void) const
{
  std::string	str;
  char		buff[2036];

  while (str.empty() || str[str.size() - 1] != '\n')
    {
      int	ret = 2036;

      while (ret == 2036)
	{
	  if ((ret = recv(this->fd, buff, 2036, 0)) == -1 || ret == 0)
	    throw My_Exception("Network: error: server close connection.");
	  buff[ret] = '\0';
	  str += buff;
	}
    }
  std::cout << "\E[34;1mServer: " << str << "\E[m";
  return (str);
}

const std::string	&Network::Ip() const
{
  return (this->ip);
}

int			Network::Port() const
{
  return (this->port);
}
