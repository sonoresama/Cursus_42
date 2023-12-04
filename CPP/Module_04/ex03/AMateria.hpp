/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:40:42 by eorer             #+#    #+#             */
/*   Updated: 2023/12/04 18:06:50 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "color.h"
//#include "ICharacter.hpp"

class AMateria
{
  public:
	AMateria();
    AMateria(std::string const &type);
	AMateria(const AMateria &cpy);
	AMateria &operator=(const AMateria &cpy);
    virtual	~AMateria ();

    std::string const & _getType() const;
    virtual AMateria* clone() const = 0;
//    virtual void use(ICharacter& target);

  protected:
    std::string const _type;
};
