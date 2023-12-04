/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:49:23 by eorer             #+#    #+#             */
/*   Updated: 2023/11/28 15:36:12 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

std::string	new_str(std::string arg)
{
	for (int i = 0; i < arg.length(); i++)
	{
		if (std::islower(arg[i]))
			arg[i] = std::toupper(arg[i]);
	}
	return (arg);
}

int	main(int argc, char **argv)
{
	if (argc <= 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; argv[i]; i++)
	{
		std::cout << new_str(argv[i]);
		if (argv[i + 1])
			std::cout << ' ';
	}
	std::cout << std::endl;
	return (0);
}
