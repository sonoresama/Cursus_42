/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:01:15 by eorer             #+#    #+#             */
/*   Updated: 2023/12/12 15:51:25 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

#define COUT(x) std::cout << x << std::endl

	//Canon
Form::Form() : _name("_default_"), _signingGrade(150), _executingGrade(150), _signed(false)
{
	COUT("Form default constructor called");
}

Form::Form(std::string name, int sGrade, int eGrade) : _name(name), _signingGrade(sGrade), _executingGrade(eGrade), _signed(false)
{
	if (sGrade < 1 || eGrade < 1)
		throw Form::GradeTooHighException();
	if (sGrade > 150 || eGrade > 150)
		throw Form::GradeTooLowException();
	COUT("Form custom constructor called");
}

Form::Form(const Form &cpy) : _name(cpy._getName()), _signingGrade(cpy._getSigningGrade()), _executingGrade(cpy._getExecutingGrade())
{
	COUT("Form cpy constructor called");
	*this = cpy;
}

Form&	Form::operator=(const Form& cpy)
{
	this->_signed = cpy._signed;
	return (*this);
}

Form::~Form()
{
	COUT("Form destructor called");
}

	//Accessors
std::string	Form::_getName() const
{
	return (this->_name);
}

bool	Form::_getSigned() const
{
	return (this->_signed);
}

int	Form::_getSigningGrade() const
{
	return (this->_signingGrade);
}

int	Form::_getExecutingGrade() const
{
	return (this->_executingGrade);
}

	//Public methods
void	Form::beSigned(const Bureaucrat& b) 
{
	if (this->_signed == true)
		return ;
	if (b._getGrade() < this->_signingGrade)
		throw Form::GradeTooHighException();
	if (b._getGrade() > this->_signingGrade)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

std::ostream& operator<<(std::ostream &out, Form const &rhs)
{
	out << rhs._getName() << " form : signed = " << rhs._getSigned() << "; sGrade : " << rhs._getSigningGrade() << "; eGrade : " << rhs._getExecutingGrade();
	return (out);
}
