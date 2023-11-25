/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:34:27 by eorer             #+#    #+#             */
/*   Updated: 2023/11/25 17:00:09 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	COUT("Default constructor has been called");
}

ClapTrap::ClapTrap(const ClapTrap &clap)
{
	COUT("Copy constructor has been called");
	this->_name = clap._name;
	this->_hit_point = clap._hit_point;
	this->_energy_point = clap._energy_point;
	this->_attack_damage = clap._attack_damage;
}

ClapTrap::~ClapTrap()
{
	COUT("Destructor has been called");
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_energy_point <= 0)
		return ;
	this
	
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_point <= 0)
		return ;
	this->_hit_point-= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_point <= 0)
		return ;
	this->_hit_point += amount;
	this->_energy_point -= 1;
	std::cout << "ClapTrap " << this->_name << " has healed " << amount << " HP" << std::endl;
}
