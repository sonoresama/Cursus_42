/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:50:09 by eorer             #+#    #+#             */
/*   Updated: 2023/11/14 17:33:01 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

void	replace_str(std::string &buffer, std::string s1, std::string s2)
{
	for (int i = 0; i + s1.length() - 1 < buffer.length(); i++)
	{
		if (!buffer.compare(i, s1.length(), s1))
		{
			buffer.erase(i, s1.length());
			buffer.insert(i, s2);
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Mauvais nombre d'arguments" << std::endl;
		return (1);
	}

	std::string buffer;
	std::string& bufferRef = buffer;
	std::string arg = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::ifstream infile(arg);
	std::ofstream outfile(arg + ".replace");

	if (!infile.is_open() || !outfile.is_open())
	{
		std::cerr << "Cannot open this file" << std::endl;
		return (1);
	}
	while (std::getline(infile, buffer))
	{
		replace_str(bufferRef, s1, s2);
		outfile << buffer << std::endl;
	}
	return (0);
}
