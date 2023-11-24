/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:00:42 by eorer             #+#    #+#             */
/*   Updated: 2023/11/17 16:31:52 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "Addresse string : " << &str << std::endl;
	std::cout << "Addresse stock dans le ptr : " << stringPTR << std::endl;
	std::cout << "Addresse stock dans la ref : " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "Valeur string : " << str << std::endl;
	std::cout << "Valeur pointeur : " << *stringPTR << std::endl;
	std::cout << "Valeur ref : " << stringREF << std::endl;
	std::cout << std::endl;
	return (0);
}
