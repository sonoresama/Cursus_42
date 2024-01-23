/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:11:23 by eorer             #+#    #+#             */
/*   Updated: 2024/01/16 13:44:51 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define COUT(x) std::cout << x << std::endl;
int main(void)
{
	try
	{
		Array<int>	i(10);
		Array<std::string>	str(10);
	
		COUT("--- Print empty arrays ---");
		std::cout << i[2] << std::endl;
		std::cout << str[2] << std::endl;
		COUT("");
	
		COUT("--- Print set arrays ---");
		i._setValue(2, 42);
		str._setValue(2, "Hello");
		std::cout << i[2] << std::endl;
		std::cout << str[2] << std::endl;
		COUT("");

		COUT("--- Print size of arrays ---");
		std::cout << i.size() << std::endl;
		std::cout << str.size() << std::endl;
		COUT("");

		COUT("--- Print copies ---");
		Array<int>	ic(i);
		Array<std::string>	sc(str);
		COUT(ic[2]);
		COUT(sc[2]);
		COUT(ic.size());
		COUT(sc.size());
		COUT("");

		COUT("--- Access out of bound indexes ---");
		std::cout << i[11] << std::endl;
		std::cout << str[11] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
