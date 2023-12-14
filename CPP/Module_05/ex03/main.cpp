/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:12:53 by eorer             #+#    #+#             */
/*   Updated: 2023/12/14 16:09:27 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Bureaucrat.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/PresidentialPardonForm.hpp"
#include "include/Intern.hpp"

#define COUT(x) std::cout << x << std::endl;

int main(void)
{
	try
	{
		Intern	noob;
		AForm	*b = noob.makeForm("ShrubberyCreationForm", "tito");
		AForm	*d = noob.makeForm("RobotomyRequestForm", "tito");
		AForm	*f = noob.makeForm("PresidentialPardonForm", "tito");
		Bureaucrat				tito("Tito", 2);

		COUT("");
		COUT(*b);
		COUT(*d);
		COUT(*f);
		COUT(tito);

		COUT("");
		tito.signForm(*b);
		tito.executeForm(*b);
		tito.signForm(*d);
		tito.executeForm(*d);
		tito.signForm(*f);
		tito.executeForm(*f);
		COUT("");

		delete b;
		delete d;
		delete f;
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << DEFAULT << std::endl;
	}
	return (0);
}
