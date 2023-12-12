/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:04:47 by eorer             #+#    #+#             */
/*   Updated: 2023/12/11 16:43:04 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

#define COUT(x) std::cout << x << std::endl;

int	main(void)
{
	IMateriaSource* src = new MateriaSource();
	AMateria* m_ice = new Ice();
	AMateria* m_cure = new Cure();

	COUT("SOURCE LEARNING");
	src->learnMateria(m_ice);
	src->learnMateria(m_cure);

	COUT("");
	COUT("SOURCE CREATING");
	AMateria* blue = src->createMateria("ice");
	AMateria* cyan = src->createMateria("ice");
	AMateria* green = src->createMateria("cure");
	AMateria* emerald = src->createMateria("cure");
	AMateria* red = src->createMateria("blood");

	COUT("");
	COUT("TITO");
	Character tito("tito");
	tito.equip(blue);
	tito.equip(cyan);
	tito.equip(green);
	tito.equip(emerald);
	tito.equip(red);
	tito.use(0, tito);
	tito.use(1, tito);
	tito.use(2, tito);
	tito.use(3, tito);
	tito.use(4, tito);

	COUT("");
	COUT("TITI (tito cpy)");
	ICharacter* titi = new Character(tito);
	titi->use(0, tito);
	titi->use(1, tito);
	titi->use(2, tito);
	titi->use(3, tito);
	titi->use(4, tito);

	COUT("");
	COUT("UNEQUIP");
	AMateria* tmp;
	tmp = blue;
	tito.unequip(0);
	tito.use(0, tito);

	COUT("");
	COUT("DELETING");
	delete(m_ice);
	delete(m_cure);
	delete(titi);
	delete(src);
	delete(tmp);
	return (0);
}
