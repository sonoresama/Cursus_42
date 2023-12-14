/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:50:39 by eorer             #+#    #+#             */
/*   Updated: 2023/12/14 14:33:51 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

	//Canon
PresidentialPardonForm::PresidentialPardonForm() : AForm("PPR", 25, 5), _target("none")
{
	std::cout << MAGENTA << "PPR default constructor called" << DEFAULT << std::endl;	
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("SCF1", 25, 5), _target(target)
{
	std::cout << MAGENTA << "PPR target constructor called" << DEFAULT << std::endl;	
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy) : AForm("PPR", 25, 5), _target(cpy._getTarget())
{
	std::cout << MAGENTA << "PPR copy constructor called" << DEFAULT << std::endl;	
	*this = cpy;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &cpy)
{
	(void)cpy;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << MAGENTA << "~ PPR default destructor called" << DEFAULT << std::endl;	
}

	//Accessors
std::string	PresidentialPardonForm::_getTarget() const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (executor._getGrade() > this->_getExecutingGrade())
		throw AForm::GradeTooLowException();
	if (!this->_getSigned())
		throw AForm::UnsignedFormException();
	std::cout << MAGENTA << this->_target << " has been pardoned by Zaphod Beeblebrox" << DEFAULT << std::endl;
}
