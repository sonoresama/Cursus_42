/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:41:56 by emileorer         #+#    #+#             */
/*   Updated: 2023/12/03 16:54:43 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class	WrongAnimal {
	public :
		WrongAnimal();
		WrongAnimal(const WrongAnimal &animal);
		~WrongAnimal();
		WrongAnimal& operator=(const WrongAnimal& animal);

		std::string _getType() const;
		void makeSound(void) const;

	protected :
		std::string type;
};
