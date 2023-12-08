/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:36:15 by eorer             #+#    #+#             */
/*   Updated: 2023/12/08 12:50:20 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	{
		ClapTrap null;
		ClapTrap tito("Tito");
		ClapTrap tito_bis(tito);
		FragTrap milou("Milou");
		FragTrap milou_bis(milou);
	
		COUT("");
		tito_bis.attack("Milou");
		milou_bis.takeDamage(150);
		milou_bis.attack("Tito");
		milou_bis.highFiveGuys();
		milou_bis.beRepaired(150);
		COUT("");
	}
	COUT("----------");
	COUT("");
	{
		ClapTrap null;
		FragTrap tito("Tito");

		COUT("");
		std::cout << "Tito energy : " << tito._get_energy_point() << std::endl;
		std::cout << "Tito life : " << tito._get_hit_point() << std::endl;
		tito.attack("no_one");
		tito.attack("no_one");
		tito.attack("no_one");
		tito.attack("no_one");
		tito.attack("no_one");
		tito.takeDamage(10);
		std::cout << "Tito energy : " << tito._get_energy_point() << std::endl;
		std::cout << "Tito life : " << tito._get_hit_point() << std::endl;

		COUT("");
		FragTrap cpy(tito);
		std::cout << "Cpy energy : " << cpy._get_energy_point() << std::endl;
		std::cout << "Cpy life : " << cpy._get_hit_point() << std::endl;
		COUT("");
	}
	return (0);
}
