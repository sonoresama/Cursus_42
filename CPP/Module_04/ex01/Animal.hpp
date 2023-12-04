/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:32:37 by emileorer         #+#    #+#             */
/*   Updated: 2023/12/03 16:48:21 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class	Animal {
	public :
		Animal();
		Animal(const Animal &animal);
		virtual ~Animal();
		Animal& operator=(const Animal& animal);

		virtual std::string _getType() const;
		virtual void makeSound(void) const;

	protected :
		std::string type;
};
