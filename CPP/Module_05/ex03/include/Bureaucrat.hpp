/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:15:46 by eorer             #+#    #+#             */
/*   Updated: 2023/12/14 14:06:19 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include "color.h"
#include "AForm.hpp"

class AForm;

class	Bureaucrat
{
  public:
	Bureaucrat();
	Bureaucrat(std::string name);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(int grade);
	Bureaucrat(const Bureaucrat &cpy);
	Bureaucrat &operator=(const Bureaucrat &cpy);
	~Bureaucrat();

		//Accessors
	std::string _getName() const;
	int _getGrade() const;

		//Public methods
	void	incrementGrade();
	void	decrementGrade();
	void	signForm(AForm& f);
	void	executeForm(AForm const &form);

		//Exception classes
	class GradeTooHighException : public std::exception
	{
	  public :
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	  public :
		const char* what() const throw();
	};

  private:
	std::string const _name;
	int				_grade;

};

std::ostream& operator<<(std::ostream &out, Bureaucrat const &rhs);