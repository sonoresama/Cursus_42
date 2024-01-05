/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:30:59 by eorer             #+#    #+#             */
/*   Updated: 2024/01/05 17:43:49 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	std::cout << "Default constructor called" << std::endl;
}

RPN::RPN(const std::string arg)
{
	std::cout << "Data constructor called" << std::endl;
	this->_parseArg(arg);
}

RPN::RPN(const RPN& cpy)
{
	std::cout << "Cpy constructor called" << std::endl;
	*this = cpy;
}

RPN& RPN::operator=(const RPN& cpy)
{
	if (this == &cpy)
		return (*this);
	this->_stack = cpy._stack;
	return (*this);
}

RPN::~RPN()
{
	std::cout << "Destructor called" << std::endl;
}
