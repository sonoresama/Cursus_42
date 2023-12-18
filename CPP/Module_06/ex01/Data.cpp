/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:12:59 by emileorer         #+#    #+#             */
/*   Updated: 2023/12/17 19:28:06 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void) : i(42), str("default")
{
	std::cout << "Data default constructor called" << std::endl;
	return ;
}

Data::Data(Data const &cpy)
{
	*this = cpy;
	return ;
}

Data::~Data(void)
{
	std::cout << "Data default destructor called" << std::endl;
	return ;
}

Data	&Data::operator=(Data const &rhs)
{
	if (this != &rhs)
	{
		this->i = rhs.i;
		this->str = rhs.str;
	}
	return (*this);
}

int	Data::getInt(void) const
{
	return (this->i);
}

std::string	Data::getStr(void) const 
{
	return (this->str);
}
