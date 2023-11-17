/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 22:56:38 by emileorer         #+#    #+#             */
/*   Updated: 2023/10/02 23:29:47 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class	Zombie
{
	public:
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void) const;
	private:
		std::string	_name;
};

#endif
