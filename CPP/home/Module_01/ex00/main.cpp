/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 22:58:49 by emileorer         #+#    #+#             */
/*   Updated: 2023/10/02 23:17:35 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

void randomChump(std::string name);
Zombie* newZombie(std::string name);

int	main(void)
{
	Zombie	zombie("stack");
	Zombie*	ptr;

	ptr = newZombie("heap");
	zombie.announce();
	ptr->announce();
	randomChump("coco");
	delete(ptr);
	return (0);
}
