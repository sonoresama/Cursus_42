/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:36:23 by emileorer         #+#    #+#             */
/*   Updated: 2023/12/03 13:43:21 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("default")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &animal)
{
	std::cout << "Animal cpy constructor called" << std::endl;
	*this = animal;
}

Animal& Animal::operator=(const Animal& animal)
{
	this->type = animal.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal default destructor called" << std::endl;
}

std::string Animal::_getType(void) const
{
	return (this->type);
}

void Animal::makeSound(void) const
{
	std::cout << "Grrrrrrrr" << std::endl;
}
