/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:21:09 by eorer             #+#    #+#             */
/*   Updated: 2023/12/06 15:23:48 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

	//CANON
Cure::Cure() : AMateria("cure")
{
	std::cout << GREEN << "Cure default constructor called" << std::endl << DEFAULT;
}

Cure::Cure(const Cure &cpy) : AMateria("cure")
{
	std::cout << GREEN << "Cure cpy constructor called" << std::endl << DEFAULT;
	*this = cpy;
}

Cure& Cure::operator=(const Cure& cpy)
{
	return (*this);
}

Cure::~Cure()
{
	std::cout << GREEN << "~ Cure default destructor called" << std::endl << DEFAULT;
}

	//METHODS
std::string const & Cure::_getType() const
{
	return (this->_type);
}

AMateria* Cure::clone() const
{
	return (new Cure());
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target._getName() << "'s wounds *" << std::endl;
}
