/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:36:15 by eorer             #+#    #+#             */
/*   Updated: 2023/12/08 12:33:39 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap null;
	ClapTrap tito("Tito");
	ClapTrap tito_bis(tito);
	ScavTrap milou("Milou");
	ScavTrap milou_bis(milou);

	COUT("");
	tito_bis.attack("Milou");
	milou_bis.takeDamage(150);
	milou_bis.attack("Tito");
	milou_bis.guardGate();
	milou_bis.beRepaired(150);
	COUT("");

	return (0);
}
