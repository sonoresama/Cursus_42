/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:40:42 by eorer             #+#    #+#             */
/*   Updated: 2023/12/06 13:20:08 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "color.h"
#include "ICharacter.hpp"

class ICharacter;

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
    virtual void use(ICharacter& target);

  protected:
    std::string const _type;
};

#endif
