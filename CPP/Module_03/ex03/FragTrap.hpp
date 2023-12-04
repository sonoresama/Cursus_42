/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:11:59 by eorer             #+#    #+#             */
/*   Updated: 2023/11/28 14:23:45 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	public :
		FragTrap();
		FragTrap(const std::string name);
		FragTrap(FragTrap& scav);
		~FragTrap();
		FragTrap& operator=(FragTrap& cpy);

		void highFiveGuys();
};
