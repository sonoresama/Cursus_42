/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:34:27 by eorer             #+#    #+#             */
/*   Updated: 2023/11/27 15:09:46 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

	//CANONICAL
ClapTrap::ClapTrap(std::string name) : _name(name)
{
	COUT("Default constructor has been called");
}

ClapTrap::ClapTrap(const ClapTrap &cpy)
{
	COUT("Copy constructor has been called");
	*this = cpy;
}

ClapTrap::~ClapTrap()
{
	COUT("Destructor has been called");
}

ClapTrap& ClapTrap::operator=(const ClapTrap &clap)
{
	this->_name = clap._name;
	this->_hit_point = clap._hit_point;
	this->_energy_point = clap._energy_point;
	this->_attack_damage = clap._attack_damage;
	return (*this);

}


	//PUBLIC FUNCTIONS
void	ClapTrap::attack(const std::string& target)
{
	if (this->_energy_point <= 0 || this->_hit_point <= 0)
		return ;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->_attack_damage << " damage" << std::endl;
	this->_energy_point -= 1;
	if (this->_energy_point == 0)
		std::cout << "ClapTrap " << this->_name << " ran out of energy" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_point <= 0)
		return ;
	std::cout << "ClapTrap " << this->_name << " took " << amount << " damage" << std::endl;
	this->_hit_point-= amount;
	if (this->_hit_point <= 0)
		std::cout << "ClapTrap " << this->_name << " ran out of life" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_point <= 0)
		return ;
	this->_hit_point += amount;
	this->_energy_point -= 1;
	std::cout << "ClapTrap " << this->_name << " has healed " << amount << " HP" << std::endl;
	if (this->_energy_point == 0)
		std::cout << "ClapTrap " << this->_name << " ran out of energy" << std::endl;
}
