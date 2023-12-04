/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:17:27 by emileorer         #+#    #+#             */
/*   Updated: 2023/12/03 17:49:44 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : public Animal {
	public :
		Cat();
		Cat(const Cat &cat);
		~Cat();
		Cat& operator=(const Cat& cat);

		std::string _getType() const;
		std::string _getIdea(int i) const;
		void	_setIdea(int i, std::string idea) const;
		void	makeSound(void) const;

	protected :
		Brain* brain;
		std::string type;
};
