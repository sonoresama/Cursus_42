/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:01:15 by eorer             #+#    #+#             */
/*   Updated: 2023/12/14 13:14:58 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"

#define COUT(x) std::cout << x << std::endl

	//Canon
AForm::AForm() : _name("_default_"), _signingGrade(150), _executingGrade(150), _signed(false)
{
	COUT("AForm default constructor called");
}

AForm::AForm(std::string name, int sGrade, int eGrade) : _name(name), _signingGrade(sGrade), _executingGrade(eGrade), _signed(false)
{
	if (sGrade < 1 || eGrade < 1)
		throw AForm::GradeTooHighException();
	if (sGrade > 150 || eGrade > 150)
		throw AForm::GradeTooLowException();
	COUT("AForm custom constructor called");
}

AForm::AForm(const AForm &cpy) : _name(cpy._getName()), _signingGrade(cpy._getSigningGrade()), _executingGrade(cpy._getExecutingGrade())
{
	COUT("AForm cpy constructor called");
	*this = cpy;
}

AForm&	AForm::operator=(const AForm& cpy)
{
	this->_signed = cpy._signed;
	return (*this);
}

AForm::~AForm()
{
	COUT("AForm destructor called");
}

	//Accessors
std::string	AForm::_getName() const
{
	return (this->_name);
}

bool	AForm::_getSigned() const
{
	return (this->_signed);
}

int	AForm::_getSigningGrade() const
{
	return (this->_signingGrade);
}

int	AForm::_getExecutingGrade() const
{
	return (this->_executingGrade);
}

	//Public methods
void	AForm::beSigned(const Bureaucrat& b) 
{
	if (this->_signed == true)
		return ;
	if (b._getGrade() > this->_signingGrade)
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

	//Exception classes
const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char *AForm::UnsignedFormException::what() const throw()
{
	return ("The form must be signed");
}

std::ostream& operator<<(std::ostream &out, AForm const &rhs)
{
	out << rhs._getName() << " form : signed = " << rhs._getSigned() << "; sGrade : " << rhs._getSigningGrade() << "; eGrade : " << rhs._getExecutingGrade();
	return (out);
}

