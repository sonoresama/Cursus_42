/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:42:28 by emileorer         #+#    #+#             */
/*   Updated: 2023/12/03 16:55:13 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal {
	public :
		WrongCat();
		WrongCat(const WrongCat &cat);
		~WrongCat();
		WrongCat& operator=(const WrongCat& cat);

		std::string _getType() const;
		void	makeSound(void) const;

	protected :
		std::string type;
};
