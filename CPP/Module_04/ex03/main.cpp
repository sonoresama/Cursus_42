/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:04:47 by eorer             #+#    #+#             */
/*   Updated: 2023/12/05 17:49:19 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"

int	main(void)
{
	Ice ice;
	Ice frozen(ice);
	AMateria* blue = new Ice();
	Character tito("tito");

	std::cout << "ice type : " << ice._getType() << std::endl;
	std::cout << "frozen type : " << frozen._getType() << std::endl;
	std::cout << "blue type : " << blue->_getType() << std::endl;

	tito.equip(blue);
	tito.use(0, tito);
	delete blue;
	return (0);
}
