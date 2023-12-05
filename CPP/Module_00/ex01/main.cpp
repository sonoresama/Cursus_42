/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:43:18 by eorer             #+#    #+#             */
/*   Updated: 2023/12/05 14:23:14 by eorer            ###   ########.fr       */
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
		std::cout << "Que voulez-vous faire (ADD, SEARCH, EXIT): ";
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
