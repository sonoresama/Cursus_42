/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:48:42 by eorer             #+#    #+#             */
/*   Updated: 2023/12/06 17:23:25 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* horde;

	if (N < 0)
		return (NULL);
	horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i]._setName(name);
	return (horde);
}
