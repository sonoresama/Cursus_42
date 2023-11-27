/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:51:42 by eorer             #+#    #+#             */
/*   Updated: 2023/11/27 18:31:43 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

	//CANONICAL
ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << this->_name<< ": ScavTrap default constructor has eben called" << std::endl;
	this->_hit_point = 100;
	this->_energy_point = 50;
	this->_attack_damage = 20;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	std::cout << this->_name<< ": ScavTrap name constructor has eben called" << std::endl;
	this->_hit_point = 100;
	this->_energy_point = 50;
	this->_attack_damage = 20;
}

ScavTrap::ScavTrap(ScavTrap &cpy)
{
	std::cout << this->_name<< ": ScavTrap copy constructor has eben called" << std::endl;
	*this = cpy;
}

ScavTrap::~ScavTrap()
{
	std::cout << this->_name<< ": ScavTrap destructor has eben called" << std::endl;
}

ScavTrap&	ScavTrap::operator=(ScavTrap &clap)
{
	this->_name = clap._get_name();
	this->_hit_point = clap._get_hit_point();
	this->_energy_point = clap._get_energy_point();
	this->_attack_damage = clap._get_attack_damage();
	return (*this);
}

	//Public Functions
void	ScavTrap::attack(const std::string &target)
{
	if (this->_energy_point <= 0 || this->_hit_point <= 0)
	{
		if(this->_energy_point <= 0)
			std::cout << "ScavTrap " << this->_name << " is out of energy" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << target << " causing " << this->_attack_damage << " damage" << std::endl;
	this->_energy_point -= 1;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now in guard mode" << std::endl;
}
