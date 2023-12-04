/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:02:31 by eorer             #+#    #+#             */
/*   Updated: 2023/12/04 18:14:45 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

	//CANON
Ice::Ice() : AMateria("ice")
{
	std::cout << TEAL << "Ice default constructor called" << std::endl << DEFAULT;
}

Ice::Ice(const Ice &cpy) : AMateria("ice")
{
	std::cout << TEAL << "Ice cpy constructor called" << std::endl << DEFAULT;
	*this = cpy;
}

Ice& Ice::operator=(const Ice& cpy)
{
//	this->_type = cpy._type;
	return (*this);
}

Ice::~Ice()
{
	std::cout << TEAL << "~ Ice default destructor called" << std::endl << DEFAULT;
}

std::string const & Ice::_getType() const
{
	return (this->_type);
}

AMateria* Ice::clone() const
{
	return (new Ice());
}
