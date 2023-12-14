/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:55:56 by eorer             #+#    #+#             */
/*   Updated: 2023/12/14 14:13:37 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include "color.h"
#include "Bureaucrat.hpp"

class Bureaucrat;

class	AForm {
	public :
		AForm();
		AForm(std::string name, int sGrade, int eGrade);
		AForm(const AForm &cpy);
		AForm &operator=(const AForm &cpy);
		virtual ~AForm() = 0;

			//Accesors
		std::string _getName() const;
		bool _getSigned() const;
		int _getSigningGrade() const;
		int _getExecutingGrade() const;

			//Public methods
		void	beSigned(const Bureaucrat& b);
		virtual void	execute(Bureaucrat const &executor) const = 0;

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

		class UnsignedFormException : public std::exception
		{
			public :
				const char* what() const throw();
		};


	private :
		std::string const _name;
		int const		_signingGrade;
		int const		_executingGrade;
		bool	_signed;
};

std::ostream& operator<<(std::ostream &out, AForm const &rhs);
