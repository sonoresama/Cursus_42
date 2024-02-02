/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:21:20 by eorer             #+#    #+#             */
/*   Updated: 2024/02/02 13:49:10 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Server.hpp"
#include "../include/irc.hpp"

void check_parameter(int argc, char **argv)
{
  std::string port;

  if (argc != 3)
    throw ("Error: not enough parameter");
  port = std::string(argv[1]);
  for (std::string::iterator c = port.begin(); c != port.end(); ++c)
  {
    if (!std::isdigit(*c))
      throw ("Error: parameters format error");
  }
}

int main(int argc, char** argv)
{
  try
  {
    check_parameter(argc, argv);
    Server  serv(std::atoi(argv[1]), std::string(argv[2]));
    pid_t pid = getpid();

    std::cout << " --> Process pid : " << pid << std::endl;
    serv.run();
  }
  catch (char const * str)
  {
    CERR(str);
    if (errno)
      perror(NULL);
    return (1);
  }
  catch (std::exception &e)
  {
    CERR(e.what());
  }
  return (0);
}
