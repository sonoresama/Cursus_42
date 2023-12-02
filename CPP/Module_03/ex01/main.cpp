/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:36:15 by eorer             #+#    #+#             */
/*   Updated: 2023/11/27 18:00:39 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap tito("Tito");
	ScavTrap milou("Milou");
	ScavTrap milou_bis(milou);

	milou_bis.attack("Tito");
	milou_bis.guardGate();
	return (0);
}
