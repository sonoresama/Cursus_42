/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:36:15 by eorer             #+#    #+#             */
/*   Updated: 2023/11/27 18:36:06 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap tito("Tito");
	ScavTrap milou("Milou");
	ScavTrap milou_bis(milou);
	FragTrap titi("Titi");

	titi.attack("Milou");
	milou_bis.attack("Milou");
	milou.takeDamage(30);
	milou.beRepaired(100);
	titi.highFiveGuys();
	return (0);
}
