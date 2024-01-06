/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 23:39:45 by emileorer         #+#    #+#             */
/*   Updated: 2024/01/06 23:48:18 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	RPN	test;

	std::cout << test._getResult(static_cast<std::string>(argv[1])) << std::endl;
	std::cout << "C BOOOOOOOOn" << '\n';
	return (0);
}
