/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:46:28 by emileorer         #+#    #+#             */
/*   Updated: 2023/12/21 13:33:13 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cmath>

Span::Span(unsigned int N) : _max_size(N)
{
	std::cout << "Span constructor called" << std::endl;
}

Span::Span(const Span &cpy) 
{
	std::cout << "Span cpy constructor called" << std::endl;
	*this = cpy;
}

Span& Span::operator=(const Span &cpy)
{
	if (this == &cpy)
		return (*this);
	this->_container = cpy._container;
	this->_max_size = cpy._max_size;
	return (*this);
}

void	Span::addNumber(int n)
{
	if (this->_container.size() >= this->_max_size)
		throw Span::NumberException();
	this->_container.push_back(n);
}

Span::~Span()
{
	std::cout << "Span default destructor called" << std::endl;
}

int	Span::shortestSpan(void)
{
	int	shortest = -1;
	int	absolute;
	std::vector<int>::iterator	it;
	std::vector<int>::iterator	bis;

	if (this->_container.size() <= 1)
		throw Span::SpanException();
	for (it = this->_container.begin(); it != this->_container.end(); it++)
	{
		for (bis = it + 1; bis != this->_container.end(); ++bis)
		{
			absolute = static_cast<int>(std::abs(*bis - *it));
			if (shortest == -1 || absolute < shortest)
				shortest = absolute;
		}
	}
	return (shortest);
}

int	Span::longestSpan(void)
{
	int	longest = -1;
	int	absolute;
	std::vector<int>::iterator	it;
	std::vector<int>::iterator	bis;

	if (this->_container.size() <= 1)
		throw Span::SpanException();
	for (it = this->_container.begin(); it != this->_container.end(); it++)
	{
		for (bis = it + 1; bis != this->_container.end(); ++bis)
		{
			absolute = static_cast<int>(std::abs(*bis - *it));
			if (longest == -1 || absolute > longest)
				longest = absolute;
		}
	}
	return (longest);
}

const char* Span::NumberException::what() const throw()
{
	return ("Maximum size reached");
}

const char* Span::SpanException::what() const throw()
{
	return ("Not enough data to compute span");
}
