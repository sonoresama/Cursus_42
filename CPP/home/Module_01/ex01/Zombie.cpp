/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 22:56:38 by emileorer         #+#    #+#             */
/*   Updated: 2023/10/02 23:34:27 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string str){
	this->_name = str;
}

Zombie::~Zombie(){
	std::cout << this->_name << " is dead" << std::endl;
}

void Zombie::announce (void) const{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
