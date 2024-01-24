/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:21:20 by eorer             #+#    #+#             */
/*   Updated: 2024/01/24 19:34:51 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/irc.hpp"

int main(void)
{
  try
  {
    Server  serv(4243, "");
    pid_t pid = getpid();

    std::cout << " --> Process pid : " << pid << std::endl;
    serv.run();
  }
  catch (char const * str)
  {
    CERR(str);
    perror(NULL);
    return (1);
  }
  return (0);
}
