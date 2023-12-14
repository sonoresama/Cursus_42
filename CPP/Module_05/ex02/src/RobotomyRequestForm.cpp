/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:22:56 by eorer             #+#    #+#             */
/*   Updated: 2023/12/14 14:33:06 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"
# include <sys/time.h>

	//Canon
RobotomyRequestForm::RobotomyRequestForm() : AForm("RRF", 72, 45), _target("none")
{
	std::cout << YELLOW << "RRF default constructor called" << DEFAULT << std::endl;	
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RRF", 72, 45), _target(target)
{
	std::cout << YELLOW << "RRF target constructor called" << DEFAULT << std::endl;	
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy) : AForm("RRF", 72, 45), _target(cpy._getTarget())
{
	std::cout << YELLOW << "RRF copy constructor called" << DEFAULT << std::endl;	
	*this = cpy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &cpy)
{
	(void)cpy;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << YELLOW << "~ RRF default destructor called" << DEFAULT << std::endl;	
}

	//Accessors
std::string	RobotomyRequestForm::_getTarget() const
{
	return (this->_target);
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	struct timeval	current_time;

	if (executor._getGrade() > this->_getExecutingGrade())
		throw AForm::GradeTooLowException();
	if (!this->_getSigned())
		throw AForm::UnsignedFormException();
	std::cout << YELLOW << "BzzZZZzZzZZzzZZzz" << DEFAULT << std::endl;
	gettimeofday(&current_time, NULL);
	if (current_time.tv_usec % 2 == 1)
		std::cout << YELLOW << this->_target << " has been robotomized" << DEFAULT << std::endl;
	else
		std::cout << YELLOW << "Robotomization failed" << DEFAULT << std::endl;
}
