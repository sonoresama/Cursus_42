/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:43:18 by eorer             #+#    #+#             */
/*   Updated: 2023/09/28 17:36:52 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main(void)
{
	PhoneBook book;
	std::string str;

	while (1)
	{
		std::cout << "Que voulez-vous faire : ";
		std::cin >> str;
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
