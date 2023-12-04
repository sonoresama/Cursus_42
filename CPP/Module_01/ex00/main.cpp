/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:30:34 by emileorer         #+#    #+#             */
/*   Updated: 2023/11/17 15:46:39 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int main(void)
{
	Zombie *zomb;

	zomb = newZombie("Tito");
	zomb->announce();
	randomChump("Titi");
	delete(zomb);
	return (0);
}
