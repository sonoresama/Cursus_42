/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 23:24:47 by emileorer         #+#    #+#             */
/*   Updated: 2023/10/02 23:36:22 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int	main(void)
{
	int	N = 10;
	Zombie* horde = zombieHorde(N, "tito");
	for (int i = 0; i < N; i++)
	{
		horde[i].announce();
		//delete(horde[i]);
	}
	return (0);
}
