/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:12:53 by eorer             #+#    #+#             */
/*   Updated: 2024/01/11 16:27:56 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat a;
		Bureaucrat b("titi", 160);
		Bureaucrat c(b);
		c.decrementGrade();
		std::cout << c << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << DEFAULT << std::endl;
	}

	return (0);
}
