/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:06:14 by emileorer         #+#    #+#             */
/*   Updated: 2024/01/08 17:25:10 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	std::ifstream file;
	std::map<std::string, double>	m;

	if (argc != 2)
	{
		std::cerr << "Bad argument number" << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange	X("data.csv");
		X.analyse(argv[1]);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
