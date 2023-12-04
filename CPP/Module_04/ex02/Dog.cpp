/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:50:46 by emileorer         #+#    #+#             */
/*   Updated: 2023/12/03 18:08:35 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

	//CANON
Dog::Dog() : Animal(), type("dog")
{
	std::cout << BLUE << "Dog default constructor called" << std::endl << DEFAULT;
	this->brain = new Brain();
}

Dog::Dog(const Dog& dog)
{
	std::cout << "Dog cpy constructor called" << std::endl;
	*this = dog;
}

Dog& Dog::operator=(const Dog& dog)
{
	this->type = dog.type;
	this->brain = new Brain(*dog.brain);
	return (*this);
}

Dog::~Dog()
{
	std::cout << BLUE << "Dog default destructor called" << std::endl << DEFAULT;
	delete this->brain;
}

std::string Dog::_getType(void) const
{
	return (this->type);
}

std::string Dog::_getIdea(int i) const
{
	return (this->brain->_getIdea(i));
}

void	Dog::_setIdea(int i, std::string idea) const
{
	this->brain->_setIdea(i, idea);
}

void	Dog::makeSound(void) const
{
	std::cout << "Wouaf Wouaf" << std::endl;
}
