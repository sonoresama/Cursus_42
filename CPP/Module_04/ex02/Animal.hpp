/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:32:37 by emileorer         #+#    #+#             */
/*   Updated: 2023/12/04 14:57:36 by eorer            ###   ########.fr       */
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
		virtual void makeSound(void) const = 0;

	protected :
		std::string type;
};
