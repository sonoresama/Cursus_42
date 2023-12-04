/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:59:19 by eorer             #+#    #+#             */
/*   Updated: 2023/12/04 18:06:46 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include "color.h"

class Ice : public AMateria {

	public : 
		Ice();
		Ice(const Ice &cpy);
		Ice &operator=(const Ice &cpy);
		~Ice ();

    	std::string const & _getType() const;
    	virtual AMateria* clone() const;
};
