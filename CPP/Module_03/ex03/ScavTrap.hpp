/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:29:33 by eorer             #+#    #+#             */
/*   Updated: 2023/11/28 14:23:35 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	public :
		ScavTrap();
		ScavTrap(const std::string name);
		ScavTrap(ScavTrap& scav);
		~ScavTrap();
		ScavTrap& operator=(ScavTrap& cpy);

		void attack(const std::string &target);
		void guardGate();
};
