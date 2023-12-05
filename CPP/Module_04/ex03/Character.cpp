/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:16:15 by eorer             #+#    #+#             */
/*   Updated: 2023/12/05 17:47:12 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

	//CANON
Character::Character() : _name("_default_")
{
	std::cout << YELLOW << "Character default constructor called" << std::endl << DEFAULT;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string name) : _name(name)
{
	std::cout << YELLOW << "Character name constructor called" << std::endl << DEFAULT;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character &cpy)
{
	std::cout << YELLOW << "Character cpy constructor called" << std::endl << DEFAULT;
	*this = cpy;
}

Character& Character::operator=(const Character& cpy)
{
	return (*this);
}

Character::~Character()
{
	std::cout << YELLOW << "~ Character default destructor called" << std::endl << DEFAULT;
}

	//METHOD
std::string const & Character::_getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria* m)
{
	int	 i;

	for (i = 0; i < 4 && this->_inventory[i] != NULL; i++) 
		;
	if (i != 4)
		this->_inventory[i] = m;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 4 || this->_inventory[idx] == NULL)
		return ;
	//	HANDLE GARBAGE MATERIA !!!!!!!!!!!!!!!!
	this->_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 4 || this->_inventory[idx] == NULL)
		return ;
	this->_inventory[idx]->use(target);
}

void	Character::cleanInventory()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
}
