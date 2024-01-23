/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:42:36 by eorer             #+#    #+#             */
/*   Updated: 2024/01/22 17:25:55 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool	isFormatOK(const std::string& str)
{
	char	tab[4] = {'+', '-', '.', 'f'};
	char	check[4] = {0, 0, 0, 0};
	int	i = 0;

    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
	{
        if (!std::isdigit(*it) && *it != '+' && *it != '-' && *it != '.' && *it != 'f')
            return false;
		for (i = 0; i < 4; i++)
		{
			if (*it == tab[i] && check[i])
				return false;
			else if (*it == tab[i])
				check[i] = 1;
		}
    }
    return true;
}

ScalarConverter::ScalarConverter()
{
	std::cout << "SC default constuctor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& cpy)
{
	*this = cpy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& cpy)
{
	(void)cpy;
	std::cout << "SC cpy constuctor called" << std::endl;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "SC default destructor called" << std::endl;
}

const char*	ScalarConverter::NonPrintableException::what() const throw()
{
	return ("Error: non printable literal");
}

void	ScalarConverter::printChar(std::string literal)
{
//	std::cout << "PRINT CHAR" << std::endl;
	std::cout << "char : " << literal[0] << "'" << std::endl;
	std::cout << "int : " << static_cast<int>(literal[0]) << std::endl;
	std::cout << "float : " << static_cast<float>(literal[0]) << ".0f" << std::endl;
	std::cout << "double : " << static_cast<double>(literal[0]) << ".0" << std::endl;
}

void	ScalarConverter::printInt(std::string literal)
{
	double	buffer = strtod(literal.c_str(), NULL);
	int		out = std::atoi(literal.c_str());

	if (out < 0 || out > 255)
		std::cout << "char : impossible" << std::endl;
	else if (!std::isprint(out))
		std::cout << "char : non displayable" << std::endl;
	else
		std::cout << "char : '" << static_cast<char>(out) << "'" << std::endl;
	if (buffer < std::numeric_limits<int>::min() || buffer > std::numeric_limits<int>::max())
	{
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : " << static_cast<float>(buffer) << std::endl;
		std::cout << "double : " << buffer <<std::endl;
		return ;
	}
	std::cout << "int : " << out << std::endl;
	std::cout << "float : " << static_cast<float>(out) << ".0f" << std::endl;
	std::cout << "double : " << static_cast<double>(out) << ".0" << std::endl;
}

void	ScalarConverter::printFloat(std::string literal)
{
	float	out = std::atof(literal.c_str());
	std::string	end_f = (out - static_cast<int>(out) == 0) ? ".0f" : "f";
	std::string	end_d = (out - static_cast<int>(out) == 0) ? ".0" : "";

//	std::cout << "PRINT FLOAT" << std::endl;
	if (out < 0 || out > 255)
		std::cout << "char : impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(out)))
		std::cout << "char : non displayable" << std::endl;
	else
		std::cout << "char : " << static_cast<char>(out) << "'" << std::endl;
	if (out < std::numeric_limits<int>::min() || out > std::numeric_limits<int>::max())
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int : " << static_cast<int>(out) << std::endl;
	std::cout << "float : " << out << end_f << std::endl;
	std::cout << "double : " << static_cast<double>(out) << end_d <<std::endl;
}

void	ScalarConverter::printDouble(std::string literal)
{
	double	out = strtod(literal.c_str(), NULL);
	std::string	end_f = (out - static_cast<int>(out) == 0) ? ".0f" : "f";
	std::string	end_d = (out - static_cast<int>(out) == 0) ? ".0" : "";

//	std::cout << "PRINT DOUBLE" << std::endl;
	if (out < 0 || out > 255)
		std::cout << "char : impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(out)))
		std::cout << "char : non displayable" << std::endl;
	else
		std::cout << "char : '" << static_cast<char>(out) << "'" << std::endl;
	if (out < std::numeric_limits<int>::min() || out > std::numeric_limits<int>::max())
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int : " << static_cast<int>(out) << std::endl;
	std::cout << "float : " << static_cast<float>(out) << end_f << std::endl;
	std::cout << "double : " << out << end_d << std::endl;
}

int		ScalarConverter::printSpecialCases(std::string literal)
{
	int	sc_f = -1;
	int	sc_d = -1;
	std::string specialCases[6] = {"+inff", "-inff", "nanf", "+inf", "-inf", "nan"};

	for (int i = 0; i < 6; i++)
	{
		if (!literal.compare(specialCases[i]) && i < 3)
		{
			sc_f = i;
			sc_d = i + 3;
		}
		else if (!literal.compare(specialCases[i]) && i >= 3)
		{
			sc_f = i - 3;
			sc_d = i;
		}
	}
	if (sc_f == -1)
		return (0);
	std::cout << "char : impossible" << std::endl;
	std::cout << "int : impossible" << std::endl;
	std::cout << "float : " << specialCases[sc_f] << std::endl;
	std::cout << "double : " << specialCases[sc_d] << std::endl;
	return (1);
}

void	ScalarConverter::convert(std::string literal)
{
	if (ScalarConverter::printSpecialCases(literal))
		return ;
	if (!isFormatOK(literal))
		throw ScalarConverter::NonPrintableException();
	if (literal.length() == 1 && !std::isdigit(literal[0]))
		ScalarConverter::printChar(literal);
	else if (literal[literal.length() - 1] == 'f')
		ScalarConverter::printFloat(literal);
	else if (literal.find(".") <= literal.length())
		ScalarConverter::printDouble(literal);
	else
		ScalarConverter::printInt(literal);
}
