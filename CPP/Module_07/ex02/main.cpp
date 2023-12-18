/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:11:23 by eorer             #+#    #+#             */
/*   Updated: 2023/12/18 16:20:26 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main(void)
{
	Array<int>	i(10);
	Array<std::string>	str(10);

	std::cout << i[2] << std::endl;
	std::cout << str[2] << std::endl;

	i._setValue(2, 42);
	str._setValue(2, "Hello");
	std::cout << i[2] << std::endl;
	std::cout << str[2] << std::endl;
	return (0);
}
