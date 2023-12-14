/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:12:53 by eorer             #+#    #+#             */
/*   Updated: 2023/12/14 14:28:33 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Bureaucrat.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/PresidentialPardonForm.hpp"

#define COUT(x) std::cout << x << std::endl;

int main(void)
{
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat();
		AForm *b = new PresidentialPardonForm("default");
		// AForm *c = new RobotomyRequestForm();
		// AForm *d = new ShrubberyCreationForm();
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << a;
		std::cout << b;

		try
		{
			b->beSigned(*a);
			// b->execute(*a);
		}
		catch (std::exception &e)
//		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[33m" << a->_getName() << " was not able to sign " << b->_getName() << ": " << e.what() << "\033[0m" << std::endl;
		}

		std::cout << b;
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		std::cout << std::endl;
	}
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;

		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat("Assistant", 145);
		Bureaucrat *b = new Bureaucrat("CEO", 1);
		AForm *c = new PresidentialPardonForm("some dude");
		// AForm *d = new AForm(*c);
		// AForm *d = new AForm("Rent Contract", 140, 100); // you are not able to construct an abstract class here
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << a;
		std::cout << b;
		std::cout << c;
		std::cout << std::endl;

		// Try to execute before signing
		try
		{
			c->execute(*b);
		}
		catch (AForm::UnsignedFormException &e)
		{
			std::cerr << "\033[33m" << a->_getName() << " was not able to execute the AForm " << c->_getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << std::endl;
		// Assistant signs the AForm
		try
		{
			c->beSigned(*a);
			// a->signAForm(*c);
		}
		catch(AForm::GradeTooLowException &e)
		{
			std::cerr << "\033[33m" << a->_getName() << " was not able to sign the AForm " << c->_getName() << ": " << e.what() << "\033[0m" << std::endl;
		}

		// CEO signs the AForm
		std::cout << std::endl;
		std::cout << c;
		std::cout << std::endl;
		try
		{
			c->beSigned(*b);
			// b->signAForm(*c);
		}
		catch(AForm::GradeTooLowException &e)
		//catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[33m" << b->_getName() << " was not able to sign the AForm " << c->_getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << std::endl;
		std::cout << c;
		std::cout << std::endl;

		// try signing the from again
		std::cout << std::endl;
		b->signForm(*c);
		std::cout << std::endl;

		// execute the AForm from assistant
		try
		{
			c->execute(*a);
			// a.executeAForm(*c);
		}
		catch(AForm::GradeTooLowException &e)
		{
			std::cerr << "\033[33m" << a->_getName() << " was not able to execute the AForm " << c->_getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << std::endl;

		// execute AForm from CEO
		try
		{
			c->execute(*b);
			// b.executeAForm(*c);
		}
		catch(AForm::GradeTooLowException &e)
		{
			std::cerr << "\033[33m" << b->_getName() << " was not able to execute the AForm " << c->_getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		delete c;
		std::cout << std::endl;
	}
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;

		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat("Emperor", 1);
		PresidentialPardonForm *b = new PresidentialPardonForm("this other dude");
		PresidentialPardonForm *c = new PresidentialPardonForm(*b);
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << a;
		std::cout << b;
		std::cout << c;
		b->beSigned(*a);
		a->signForm(*c);
		b->execute(*a);
		a->executeForm(*c);
		// c->execute(*a);
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		delete c;
		std::cout << std::endl;
	}
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;

		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat("Emperor", 1);
		RobotomyRequestForm *b = new RobotomyRequestForm("Bender");
		ShrubberyCreationForm *c = new ShrubberyCreationForm("christmas");
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << a;
		std::cout << b;
		std::cout << c;
		b->beSigned(*a);
		a->signForm(*c);
		for (int i= 0; i < 10; i++)
			b->execute(*a);
		// a->executeAForm(*c);
		c->execute(*a);
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		delete c;
		std::cout << std::endl;
	}
	return (0);
}

//int	main(void)
//{
//	try
//	{
//		ShrubberyCreationForm	a("home");
//		ShrubberyCreationForm	b(a);
//		RobotomyRequestForm		c("titi");
//		RobotomyRequestForm		d(c);
//		PresidentialPardonForm		e("zeus");
//		PresidentialPardonForm		f(e);
//		Bureaucrat				tito("Tito", 2);
//
//		COUT("");
//		COUT(b);
//		COUT(d);
//		COUT(f);
//		COUT(tito);
//
//		COUT("");
//		tito.signForm(b);
//		tito.executeForm(b);
//		tito.signForm(d);
//		tito.executeForm(d);
//		tito.signForm(f);
//		tito.executeForm(f);
//		COUT("");
//	}
//	catch (std::exception &e)
//	{
//		std::cout << RED << e.what() << DEFAULT << std::endl;
//	}
//	return (0);
//}
