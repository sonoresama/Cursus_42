/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:45:07 by eorer             #+#    #+#             */
/*   Updated: 2023/12/15 18:09:21 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int	main(int argc, char **argv)//, char **env)
{
	std::string str;

	if (argc != 2)
		return (0);
	try
	{
		ScalarConverter::convert(argv[1]);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
//	std::cout << std::endl;
//	if (fork() == 0)
//		execve("test/cpp-module-06/ex00/out", argv, env);
//	else
//		wait(NULL);
	return (0);
}
