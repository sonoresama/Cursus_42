/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:13:53 by eorer             #+#    #+#             */
/*   Updated: 2023/12/05 17:44:17 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ICharacter.hpp"

class	Character : public ICharacter
{
	public :
		Character();
		Character(std::string name);
		Character (const Character& cpy);
		Character &operator=(const Character& cpy);
		~Character();

		std::string const & _getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

		void	cleanInventory();
	
	private :
		std::string	_name;
		AMateria* _inventory[4];
//		AMateria* _garbage[100];
};
