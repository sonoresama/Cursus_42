/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:40:17 by eorer             #+#    #+#             */
/*   Updated: 2024/01/09 17:24:02 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
  if (argc <= 2)
  {
    std::cout << "Not enough arguments" << std::endl;
    return (1);
  }
  try
  {
   PmergeMe  test;
   test.sort(argv);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }

  return (0);
}
