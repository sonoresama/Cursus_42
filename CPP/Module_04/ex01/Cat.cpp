/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:18:38 by emileorer         #+#    #+#             */
/*   Updated: 2023/12/03 18:07:57 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

	//CANON
Cat::Cat() : Animal(), type("cat")
{
	std::cout << GREEN << "Cat default constructor called" << std::endl << DEFAULT;
	this->brain = new Brain();
}

Cat::Cat(const Cat &cat)
{
	std::cout << "Cat cpy constructor called" << std::endl;
	*this = cat;
}

Cat& Cat::operator=(const Cat &cat)
{
	this->type = cat.type;
	this->brain = new Brain(*cat.brain);
	return (*this);
}

Cat::~Cat()
{
	std::cout << GREEN << "Cat default destructor called" << std::endl << DEFAULT;
	delete this->brain;
}

std::string Cat::_getType(void) const
{
	return (this->type);
}

std::string Cat::_getIdea(int i) const
{
	return (this->brain->_getIdea(i));
}

void	Cat::_setIdea(int i, std::string idea) const
{
	this->brain->_setIdea(i, idea);
}

void	Cat::makeSound(void) const
{
	std::cout << "Miaou Miaou" << std::endl;
}
