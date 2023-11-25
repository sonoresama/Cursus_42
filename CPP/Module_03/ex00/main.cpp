/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:42:31 by eorer             #+#    #+#             */
/*   Updated: 2023/11/25 16:47:14 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap test("Milou");
	ClapTrap cpy(test);

	test.announce();
	cpy.announce();
	test.announce_health();
	cpy.announce_health();
	return (0);
}
