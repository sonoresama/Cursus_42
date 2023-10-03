/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:50:09 by eorer             #+#    #+#             */
/*   Updated: 2023/10/03 19:39:47 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

//void	replace_buffer(std::string *buffer, s1, s2)
//{
//	std::string delimiter = " ";
//	std::string token;
//	int	pos = 0;
//	int	i = 0;
//
//	while ((pos = buffer.find(delimiter)) != -1)
//	{
//		token = buffer.substr(i, pos);
//	
//		i = pos + delimiter.length(); 
//	}
//
//}

void	replace_str(std::string *buffer, std::string s1, std::string s2)
{
	for (int i = 0; i + s1.length() < buffer->length(); i++)
	{
		if (!buffer->compare(i, s1.length() -1, s1))
		{
			std::cout << "J'AI TROUVE !!!!!!!" << std::endl;
			buffer->erase(i, s1.length());
			buffer->insert(i, s2);
		}
	}
}

//int	main(void)
//{
//	std::string buffer = "Le loup est la";
//	std::string s1 = "loup";
//	std::string s2 = "cheval";
//	std::ofstream outfile("exit");
//	std::ifstream infile("enter");
//
//	std::cout << buffer << std::endl;
//	infile >> buffer;
//	replace_str(&buffer, s1, s2);
//	outfile << buffer << std::endl;
//}

int	main(int argc, char **argv)
{
	std::string s1, s2;
	std::string arg;
	std::string buffer;
	std::ifstream infile;
	std::ofstream outfile;

	if (argc != 4)
	{
		std::cout << "Mauvais nombre d'arguments" << std::endl;
		return (1);
	}
	arg = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	infile.open(arg);
	outfile.open(arg + ".replace");
	if (!infile.is_open() || !outfile.is_open())
	{
		std::cout << "not opened" << std::endl;
		return (1);
	}
	while (std::getline(infile, buffer))
	{
		std::cout << buffer << std::endl;//"           ";
		replace_str(&buffer, s1, s2);
//		std::cout << buffer << std::endl;
		outfile << buffer << std::endl;
	}
	infile.close();
	outfile.close();
	return (0);
}
