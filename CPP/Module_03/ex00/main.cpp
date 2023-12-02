/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:42:31 by eorer             #+#    #+#             */
/*   Updated: 2023/11/27 15:07:06 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap milou("Milou");
	ClapTrap cpy(milou);
	ClapTrap tito("Tito");

	cpy.attack("Tito");
	tito.takeDamage(11);
	tito.beRepaired(15);
	tito.attack("Milou");
	return (0);
}
