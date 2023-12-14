/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:45:08 by eorer             #+#    #+#             */
/*   Updated: 2023/12/14 16:01:51 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"
#include "../include/color.h"

Intern::Intern()
{
	std::cout << CYAN << "Intern default constructor called" << DEFAULT << std::endl;
}

Intern::Intern(const Intern &cpy)
{
	std::cout << CYAN << "Intern cpy constructor called" << DEFAULT << std::endl;
	*this = cpy;
}

Intern& Intern::operator=(const Intern &cpy)
{
	(void)cpy;
	return (*this);
}

Intern::~Intern()
{
	std::cout << CYAN << "Intern default destructor called" << DEFAULT << std::endl;
}

AForm*	Intern::formSCF(std::string tName)
{
	return (new ShrubberyCreationForm(tName));
}

AForm*	Intern::formRRF(std::string tName)
{
	return (new RobotomyRequestForm(tName));
}

AForm*	Intern::formPPF(std::string tName)
{
	return (new PresidentialPardonForm(tName));
}

AForm*	Intern::makeForm(std::string fName, std::string tName)
{
	AForm* ptr = NULL;
	AForm* (Intern::*f[3])(std::string);
	std::string names[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	
	f[0] = &Intern::formSCF;
	f[1] = &Intern::formRRF;
	f[2] = &Intern::formPPF;
	for (int i = 0; i < 3; i++)
	{
		if (names[i] == fName)
			ptr = (this->*f[i])(tName);
	}
	if (ptr)
		std::cout << CYAN << "Intern successfully created form " << fName << DEFAULT << std::endl;
	else
		std::cout << CYAN << "Intern does not know form " << fName << DEFAULT << std::endl;
	return (ptr);
}
