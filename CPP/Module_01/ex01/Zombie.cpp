/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:37:58 by eorer             #+#    #+#             */
/*   Updated: 2023/12/06 17:18:40 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() 
{
	std::cout << "Un zombie a ete cree" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Le zombie " << this->_name << " est mort" << std::endl;
}

void	Zombie::announce(void) const{
	std::cout << this->_name << ": BraiiiiiiinnnzzZ..." << std::endl;
}

void	Zombie::_setName(std::string name)
{
	this->_name = name;
}
