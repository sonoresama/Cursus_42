/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:04:05 by eorer             #+#    #+#             */
/*   Updated: 2023/11/28 14:25:06 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamonTrap : public ScavTrap, public FragTrap
{
	public :
		DiamonTrap();

	private:
			std::string _name;
};
