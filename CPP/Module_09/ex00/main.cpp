/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:06:14 by emileorer         #+#    #+#             */
/*   Updated: 2024/01/04 16:11:03 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//int	ft_parsing(std::ifstream& file)
//{
//	std::string line;
//
//	//check if file is empty
//	getline(file, line);
//	if (line != "date | value")
//	{
//		std::cerr << "Format error" << std::endl;
//		return (1);
//	}
//	while (std::getline(file, line))
//	{
//		std::cout << line << std::endl;
//	}
//	return (0);
//}

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
	//	m = X._getMap();
	//	std::map<std::string, double>::iterator it = m.begin();
	//	std::cout << it->first << " " << it->second << std::endl;
		X.analyse(argv[1]);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
