//
// exception.hpp for Zappy_IA in /home/cisner_d/ZAPPY/IA_CLIENT
// 
// Made by [D[C[3~[3~[3~
// Login   <cisner_d@epitech.net>
// 
// Started on  Sat May  3 14:16:24 2014 [D[C[3~[3~[3~
// Last update Sat May  3 14:55:01 2014 [D[C[3~[3~[3~
//

#ifndef		EXCEPTION_HPP_
# define	EXCEPTION_HPP_

# include	<string>
# include	<iostream>
# include	<stdexcept>

class		My_Exception : public std::exception
{
private:
  std::string	msg;

public:
  My_Exception(const std::string &def = "Default exception thrown") : msg(def) {}
  virtual ~My_Exception() throw() {}

  const char*	what()
  {
    return (msg.c_str());
  }
};

#endif
