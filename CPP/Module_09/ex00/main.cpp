/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:06:14 by emileorer         #+#    #+#             */
/*   Updated: 2024/01/03 16:36:04 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

int	ft_parsing(std::ifstream& file)
{
	std::string line;

	//check if file is empty
	getline(file, line);
	if (line != "date | value")
	{
		std::cerr << "Format error" << std::endl;
		return (1);
	}
	while (std::getline(file, line))
	{
		std::cout << line << std::endl;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	std::ifstream file;

	if (argc != 2)
	{
		std::cerr << "Bad argument number" << std::endl;
		return (1);
	}
	file.open(argv[1]);
	if (!file.is_open())
	{
		std::cerr << "File not found" << std::endl;
		return (1);
	}
	try
	{	
		if (ft_parsing(file))
			return (1);
		file.close();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "DONE\n";
	return (0);
}
