/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:23:28 by eorer             #+#    #+#             */
/*   Updated: 2023/12/06 16:55:26 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << MAGENTA << "MateriaSource default constructor called" << DEFAULT << std::endl;
	for (int i = 0; i < 4; i++)
		this->_models[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& cpy)
{
	std::cout << MAGENTA << "MateriaSource copy constructor called" << DEFAULT << std::endl;
	*this = cpy;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& cpy)
{
	for (int i = 0; i < 4; i++)
		this->_models[i] = cpy._models[i];
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << MAGENTA << "~ MateriaSource default destructor called" << DEFAULT << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_models[i] != NULL)
			delete this->_models[i];
	}
}

void	MateriaSource::learnMateria(AMateria* m)
{
	int	i;

	for (i = 0; i < 4 && this->_models[i] != NULL; i++)
		;
	this->_models[i] = m->clone();
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int	i;

	std::string	known_type;
	for (i = 0; i < 4 && this->_models[i] != NULL; i++)
	{
		known_type = this->_models[i]->_getType();
		if (known_type.compare(type) == 0)
			return (this->_models[i]->clone());
	}
	std::cout << RED << " ! TYPE UNKNOWN BY MATERIA SOURCE !" << DEFAULT << std::endl;
	return (NULL);
}
