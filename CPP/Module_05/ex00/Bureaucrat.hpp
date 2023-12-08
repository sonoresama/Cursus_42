/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:15:46 by eorer             #+#    #+#             */
/*   Updated: 2023/12/08 17:30:11 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include "color.h"

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

		//Exception classes
	class GradeTooHighException : public std::exception
	{
	  public :
		const char* what() const throw()
		{
			return ("Grade is too high");
		}
	};

	class GradeTooLowException : public std::exception
	{
	  public :
		const char* what() const throw()
		{
			return ("Grade is too low");
		}
	};

  private:
	std::string const _name;
	int				_grade;

};

std::ostream& operator<<(std::ostream &out, Bureaucrat const &rhs);
