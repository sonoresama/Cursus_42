/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:43:18 by eorer             #+#    #+#             */
<<<<<<< HEAD:CPP/home/Module_00/ex01/main.cpp
/*   Updated: 2023/10/01 14:21:32 by emileorer        ###   ########.fr       */
=======
/*   Updated: 2023/10/02 17:11:13 by eorer            ###   ########.fr       */
>>>>>>> 0fcc48fbcff29450fe18c43f73966fd039aace6e:CPP/Module_00/ex01/main.cpp
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include <string>
#include <cctype>

int	main(void)
{
	PhoneBook book;
	std::string str;

	while (1)
	{
		std::cout << "Que voulez-vous faire : ";
		std::getline(std::cin, str);
		if (str.empty())
			continue;
		if (!str.compare("EXIT"))
		{
			std::cout << "GOODBYE :)" << std::endl;
			return (0);
		}
		else
			book.init_phonebook(str);
	}
	return (0);
}
