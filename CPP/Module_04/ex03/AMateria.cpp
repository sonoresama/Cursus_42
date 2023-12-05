/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:43:21 by eorer             #+#    #+#             */
/*   Updated: 2023/12/05 17:48:26 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

	//CANON
AMateria::AMateria() : _type("default")
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &str) : _type(str)
{
	std::cout << "AMateria type constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &cpy)
{
	std::cout << "AMateria cpy constructor called" << std::endl;
	*this = cpy;
}

AMateria& AMateria::operator=(const AMateria& cpy)
{
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "~ AMateria default destructor called" << std::endl;
}

	//METHODS
std::string const & AMateria::_getType() const
{
	return (this->_type);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "Prout" << std::endl;
}
