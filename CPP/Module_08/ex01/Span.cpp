/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:46:28 by emileorer         #+#    #+#             */
/*   Updated: 2024/01/18 15:34:40 by eorer            ###   ########.fr       */
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

Span::~Span()
{
	std::cout << "Span default destructor called" << std::endl;
}


std::vector<int>::iterator Span::_begin()
{
	return (this->_container.begin());
}

std::vector<int>::iterator Span::_end()
{
	return (this->_container.end());
}

void	Span::addNumber(int n)
{
	if (this->_container.size() >= this->_max_size)
		throw Span::NumberException();
	this->_container.push_back(n);
}

void	Span::addRange(int _range)
{
	int	r;

	std::srand(static_cast<unsigned>(std::time(0)));
	for (int i = 0; i < _range; i++)
	{
		r = std::rand() % 1000 + 1;
		this->addNumber(r);
	}
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

const char* Span::OORException::what() const throw()
{
	return ("addRange: iterator not in Span container");
}
