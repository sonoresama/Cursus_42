/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:20:22 by eorer             #+#    #+#             */
/*   Updated: 2023/12/05 17:08:16 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include "color.h"

class Cure : public AMateria {

	public : 
		Cure();
		Cure(const Cure &cpy);
		Cure &operator=(const Cure &cpy);
		~Cure ();

    	std::string const & _getType() const;
		void use(ICharacter& target);
    	AMateria* clone() const;
};
