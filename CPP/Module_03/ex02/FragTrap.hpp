/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:11:59 by eorer             #+#    #+#             */
/*   Updated: 2023/12/08 12:38:20 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public :
		FragTrap();
		FragTrap(const std::string name);
		FragTrap(FragTrap& scav);
		~FragTrap();
		FragTrap& operator=(FragTrap& cpy);

		void highFiveGuys();
};

#endif
