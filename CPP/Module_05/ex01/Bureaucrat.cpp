/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:53:32 by eorer             #+#    #+#             */
/*   Updated: 2023/12/14 16:20:04 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

	//CANON
Bureaucrat::Bureaucrat() : _name("_default_"),  _grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(150)
{
	std::cout << "Bureaucrat name constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Bureaucrat name & grade constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(int grade) : _name("_default_"), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Bureaucrat grade constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy) : _name(cpy._getName())
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = cpy;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &cpy) 
{
	this->_grade = cpy._getGrade();
	return (*this);
}

Bureaucrat :: ~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

	//ACCESSORS
std::string Bureaucrat::_getName() const
{
	return (this->_name);
}

int	Bureaucrat::_getGrade() const
{
	return (this->_grade);
}

	//PUBLIC METHODS
void	Bureaucrat::incrementGrade()
{
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void	Bureaucrat::signForm(Form& f)
{
	if (f._getSigned())
		std::cout << "bureaucrat " << this->_name << " couldn't sign form " << f._getName() << " because form is already signed" << std::endl;
	f.beSigned(*this);
	std::cout << "bureaucrat " << this->_name << " signed form " << f._getName() << std::endl;
}

	//Exception classes
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream& operator<<(std::ostream &out, Bureaucrat const &rhs)
{
	out << rhs._getName() << ", bureaucrat grade " << rhs._getGrade() << ".";
	return (out);
}
