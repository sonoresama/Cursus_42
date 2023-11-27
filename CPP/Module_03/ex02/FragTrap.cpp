/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:11:34 by eorer             #+#    #+#             */
/*   Updated: 2023/11/27 18:35:41 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

	//CANONICAL
FragTrap::FragTrap() : ClapTrap()
{
	std::cout << this->_name<< ": FragTrap default constructor has eben called" << std::endl;
	this->_hit_point = 100;
	this->_energy_point = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	std::cout << this->_name<< ": FragTrap name constructor has eben called" << std::endl;
	this->_hit_point = 100;
	this->_energy_point = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap(FragTrap &cpy)
{
	std::cout << this->_name<< ": FragTrap copy constructor has eben called" << std::endl;
	*this = cpy;
}

FragTrap::~FragTrap()
{
	std::cout << this->_name<< ": FragTrap destructor has eben called" << std::endl;
}

FragTrap&	FragTrap::operator=(FragTrap &clap)
{
	this->_name = clap._get_name();
	this->_hit_point = clap._get_hit_point();
	this->_energy_point = clap._get_energy_point();
	this->_attack_damage = clap._get_attack_damage();
	return (*this);
}


// PUBLIC FUNCTIONS
void	FragTrap::highFiveGuys(void)
{
	COUT("HIGH FIVES");
}
