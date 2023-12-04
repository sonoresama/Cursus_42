/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:46:33 by emileorer         #+#    #+#             */
/*   Updated: 2023/12/03 17:11:52 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class	Dog : public Animal {
	public :
		Dog();
		Dog(const Dog &dog);
		~Dog();
		Dog& operator=(const Dog& dog);

		std::string _getType() const;
		void	makeSound(void) const;

	protected :
		std::string type;
};
