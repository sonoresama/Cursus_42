/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:22:43 by emileorer         #+#    #+#             */
/*   Updated: 2023/11/17 15:43:59 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string str) : name(str){
	std::cout << this->name << ": has been created" << std::endl;
}

Zombie::~Zombie()
{
		std::cout << this->name << ": has been destroyed" << std::endl;
}

void	Zombie::announce() const{
	std::cout << this->name << ": Braiiiiinzz" << std::endl;
}
