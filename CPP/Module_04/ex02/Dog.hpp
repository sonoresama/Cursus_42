/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:46:33 by emileorer         #+#    #+#             */
/*   Updated: 2023/12/06 14:39:58 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal {
	public :
		Dog();
		Dog(const Dog &dog);
		~Dog();
		Dog& operator=(const Dog& dog);

		std::string _getType() const;
		std::string _getIdea(int i) const;
		void	_setIdea(int i, std::string idea) const;
		void	makeSound(void) const;

	protected :
		Brain* brain;
		std::string type;
};
