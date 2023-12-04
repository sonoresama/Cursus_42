/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:09:57 by emileorer         #+#    #+#             */
/*   Updated: 2023/12/03 18:09:05 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << MAGENTA << "Brain created" << std::endl << DEFAULT;
	return ;
}

Brain::~Brain(void)
{
	std::cout << MAGENTA << "Brain destroyed" << std::endl << DEFAULT;
	return ;
}

Brain::Brain(Brain const &cpy)
{
	*this = cpy;
	return ;
}

Brain&	Brain::operator=(Brain const &cpy)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = cpy.ideas[i];
	return (*this);
}

void	Brain::_setIdea(int i, std::string idea)
{
	this->ideas[i] = idea;
}

std::string	Brain::_getIdea(int i) const
{
	return (this->ideas[i]);
}
