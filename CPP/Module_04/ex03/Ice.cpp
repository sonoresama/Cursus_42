/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:02:31 by eorer             #+#    #+#             */
/*   Updated: 2023/12/06 16:53:11 by eorer            ###   ########.fr       */
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

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target._getName() << " *" << std::endl;
}
