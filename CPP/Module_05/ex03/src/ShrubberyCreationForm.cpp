/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:26:30 by eorer             #+#    #+#             */
/*   Updated: 2023/12/14 14:14:54 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

	//Canon
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("SCF", 145, 137), _target("none")
{
	std::cout << GREEN << "SCF default constructor called" << DEFAULT << std::endl;	
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("SCF", 145, 137), _target(target)
{
	std::cout << GREEN << "SCF target constructor called" << DEFAULT << std::endl;	
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy) : AForm("SCF", 145, 137), _target(cpy._getTarget())
{
	std::cout << GREEN << "SCF copy constructor called" << DEFAULT << std::endl;	
	*this = cpy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &cpy)
{
	(void)cpy;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << GREEN << "~ SCF default destructor called" << DEFAULT << std::endl;	
}

	//Accessors
std::string	ShrubberyCreationForm::_getTarget() const
{
	return (this->_target);
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	std::string title = this->_target + "_shrubbery";
	std::ofstream file; 

	if (executor._getGrade() > this->_getExecutingGrade())
		throw AForm::GradeTooLowException();
	if (!this->_getSigned())
		throw AForm::UnsignedFormException();
	file.open(title.c_str(), std::ios::trunc);
	if (!file.is_open())
		return ;
	file <<
			"         v" << std::endl <<
			"        >X<" << std::endl <<
			"         A" << std::endl <<
			"        d$b" << std::endl <<
			"      .d\\$$b." << std::endl <<
			"    .d$i$$\\$$b." << std::endl <<
			"       d$$@b" << std::endl <<
			"      d\\$$$ib" << std::endl <<
			"    .d$$$\\$$$b" << std::endl <<
			"  .d$$@$$$$\\$$ib." << std::endl <<
			"      d$$i$$b" << std::endl <<
			"     d\\$$$$@$b" << std::endl <<
			"  .d$@$$\\$$$$$@b." << std::endl <<
			".d$$$$i$$$\\$$$$$$b." << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl <<
		std::endl;
	file.close();
}
