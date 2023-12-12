/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:34:27 by eorer             #+#    #+#             */
/*   Updated: 2023/12/11 13:50:17 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

	//CANONICAL

ClapTrap::ClapTrap(void) : _name("no_one"), _hit_point(10), _energy_point(10), _attack_damage(0)
{
	std::cout << "ClapTrap " << this->_name << " default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_point(10), _energy_point(10), _attack_damage(0)
{
	std::cout << "ClapTrap " << this->_name << " name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &cpy)
{
	*this = cpy;
	std::cout << "ClapTrap " << this->_name << " cpy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &clap)
{
	this->_name = clap._name;
	this->_hit_point = clap._hit_point;
	this->_energy_point = clap._energy_point;
	this->_attack_damage = clap._attack_damage;
	return (*this);
}

	//ACCESSORS
std::string ClapTrap::_get_name()
{
	return (this->_name);
}

int	ClapTrap::_get_hit_point()
{
	return (this->_hit_point);
}

int	ClapTrap::_get_energy_point()
{
	return (this->_energy_point);
}

int	ClapTrap::_get_attack_damage()
{
	return (this->_attack_damage);
}

void ClapTrap::_set_hit_point(int i)
{
	if (i >= 0)
		this->_hit_point = i;
}

void ClapTrap::_set_energy_point(int i)
{
	if (i >= 0)
		this->_energy_point = i;
}

void ClapTrap::_set_attack_damage(int i)
{
	if (i >= 0)
		this->_attack_damage = i;
}

	//PUBLIC FUNCTIONS
void	ClapTrap::attack(const std::string& target)
{
	if (this->_energy_point <= 0 || this->_hit_point <= 0)
	{
		if(this->_energy_point <= 0)
			std::cout << "ClapTrap " << this->_name << " is out of energy" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->_attack_damage << " damage" << std::endl;
	this->_energy_point -= 1;
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
	if (this->_energy_point <= 0 || this->_hit_point <= 0)
	{
		if(this->_energy_point <= 0)
			std::cout << "ClapTrap " << this->_name << " is out of energy" << std::endl;
		return ;
	}
	this->_hit_point += amount;
	this->_energy_point -= 1;
	std::cout << "ClapTrap " << this->_name << " has healed " << amount << " HP" << std::endl;
}
