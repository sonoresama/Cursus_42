/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:17:27 by emileorer         #+#    #+#             */
/*   Updated: 2023/12/03 17:11:34 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class	Cat : public Animal {
	public :
		Cat();
		Cat(const Cat &cat);
		~Cat();
		Cat& operator=(const Cat& cat);

		std::string _getType() const;
		void	makeSound(void) const;

	protected :
		std::string type;
};
