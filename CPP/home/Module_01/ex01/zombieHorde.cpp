/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 23:20:50 by emileorer         #+#    #+#             */
/*   Updated: 2023/10/02 23:36:52 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* horde;

	horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i] = zombie(name);
	return (horde);
}
