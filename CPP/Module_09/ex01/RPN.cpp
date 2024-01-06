/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:30:59 by eorer             #+#    #+#             */
/*   Updated: 2024/01/06 23:47:46 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stdlib.h>

static bool	is_operator(char op)
{
	switch (op)
	{
		case '+': 
					 return true;
		case '-': 
					 return true;
		case '/': 
					 return true;
		case '*': 
					 return true;
	}
	return (false);
}

RPN::RPN() : _result(0)
{
	std::cout << "Default constructor called" << std::endl;
}

//RPN::RPN(const std::string arg) : _result(0)
//{
//	std::cout << "Data constructor called" << std::endl;
//	this->_parseArg(arg);
//}

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

std::stack<int>	RPN::_getStack()
{
	return (this->_stack);
}

int	RPN::_getResult()
{
		return (this->_result);
}

int	RPN::_getResult(std::string operation)
{
	int	num;

	for (std::string::iterator it = operation.begin(); it != operation.end(); ++it)
	{
		if (*it == ' '){
			std::cout << "Space" << '\n';
			continue ;}
		std::cout << "Diez" << '\n';
		if (!is_operator(*it))
			this->_stack.push(static_cast<int>(*it - 48));
		else
			num = this->_stack.top();
			this->_stack.pop();
			switch (*it)
			{
				case '+':
					num = num + this->_stack.top();
				case '-':
					num = num - this->_stack.top();
				case '/':
					num = num / this->_stack.top();
				case '*':
					num = num * this->_stack.top();
			}
			this->_stack.pop();
			this->_stack.push(num);
	}
	this->_result = num;
	this->_stack.pop();
	std::cout << "Done" << '\n';
	return (this->_result);
}
