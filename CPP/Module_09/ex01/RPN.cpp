/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:30:59 by eorer             #+#    #+#             */
/*   Updated: 2024/01/19 14:29:01 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stdlib.h>
#include <cctype>
#include <string>

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

	//CANON
RPN::RPN() : _result(0)
{
	std::cout << "Default constructor called" << std::endl;
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
	int	num1;
	int	num2;

	this->_checkArg(operation);
	for (std::string::iterator it = operation.begin(); it != operation.end(); ++it)
	{
		if (*it == ' '){
			continue ;}
		if (!is_operator(*it))
			this->_stack.push(static_cast<int>(*it - 48));
		else
		{
			if (this->_stack.empty())
				throw RPN::FormatError();
			num1 = this->_stack.top();
			this->_stack.pop();
			if (this->_stack.empty())
				throw RPN::FormatError();
			num2 = this->_stack.top();
			this->_stack.pop();
			switch (*it)
			{
				case '+':
					this->_stack.push(num2 + num1);
					break;
				case '-':
					this->_stack.push(num2 - num1);
					break;
				case '/':
					if (num1 == 0)
						throw RPN::ZeroDivError();
					this->_stack.push(num2 / num1);
					break;
				case '*':
					this->_stack.push(num2 * num1);
					break;
			}
		}
	}
	this->_result = this->_stack.top();
	this->_stack.pop();
	if (!this->_stack.empty())
		throw RPN::FormatError();
	return (this->_result);
}

void	RPN::_checkArg(std::string arg)
{
	std::string::iterator next_it;
	for (std::string::iterator it = arg.begin(); it != arg.end(); ++it)
	{
		if (!is_operator(*it) && !std::isdigit(*it) && *it != ' ')
			throw RPN::FormatError();
		next_it = it;
		++next_it;
		if (std::isdigit(*it) && next_it != arg.end() && std::isdigit(*next_it))
			throw RPN::FormatError();
	}
}

void	RPN::_printStack()
{
	std::stack<int>	tmp = this->_stack;

	std::cout << "Stack : ";
	while (!tmp.empty())
	{
		std::cout << tmp.top() << " ";
		tmp.pop();
	}
	std::cout << std::endl;
}

const char*	RPN::FormatError::what() const throw()
{
	return ("Format error");
}

const char*	RPN::ZeroDivError::what() const throw()
{
	return ("Error: divided by 0");
}
