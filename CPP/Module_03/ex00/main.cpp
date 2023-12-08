/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:42:31 by eorer             #+#    #+#             */
/*   Updated: 2023/12/08 12:24:05 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap null;
	ClapTrap milou("Milou");
	ClapTrap cpy(milou);
	ClapTrap tito("Tito");

	COUT("");
	null.attack("_nobody_");
	cpy.attack("Tito");
	tito.takeDamage(11);
	tito.beRepaired(15);
	tito.attack("Milou");
	COUT("");
	return (0);
}
