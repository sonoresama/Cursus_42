/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:08:39 by emileorer         #+#    #+#             */
/*   Updated: 2023/12/03 17:54:27 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "color.h"

class Brain
{
	public:
		Brain(void);
		~Brain(void);
		Brain(Brain const &cpy);
		Brain&	operator=(Brain const &cpy);

		void	_setIdea(int i, std::string idea);
		std::string	_getIdea(int i) const;

	private:
		std::string		ideas[100];
};
