/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:40:17 by eorer             #+#    #+#             */
/*   Updated: 2024/01/08 19:02:21 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
  (void)argc;
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
