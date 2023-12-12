/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:20:58 by eorer             #+#    #+#             */
/*   Updated: 2023/12/06 13:20:04 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTHER_HPP
# define ICHARACTHER_HPP

# include "AMateria.hpp"

class AMateria;

class ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const & _getName() const = 0;
		virtual void equip(AMateria *m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif