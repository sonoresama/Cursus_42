/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:40:49 by eorer             #+#    #+#             */
/*   Updated: 2023/12/15 17:46:57 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>

class ScalarConverter
{
	public :
		ScalarConverter();
		ScalarConverter(const ScalarConverter& cpy);
		ScalarConverter& operator=(const ScalarConverter& cpy);
		virtual ~ScalarConverter() = 0;

		static void	convert(std::string literal);
		class	NonPrintableException : public std::exception
		{
			public :
				const char* what() const throw();
		};

	private :
		static 	void	printChar(std::string literal);
		static 	void	printInt(std::string literal);
		static 	void	printFloat(std::string literal);
		static 	void	printDouble(std::string literal);
		static 	int		printSpecialCases(std::string literal);
};
