/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:15:29 by emileorer         #+#    #+#             */
/*   Updated: 2023/12/17 19:28:48 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{
	std::cout << "Serializer default constructor called" << std::endl;
	return ;
}

Serializer::Serializer(Serializer const &cpy)
{
	*this = cpy;
	return ;
}

Serializer	&Serializer::operator=(Serializer const &rhs)
{
	(void)rhs;
	return (*this);
}

Serializer::~Serializer(void)
{
	std::cout << "Serializer default destructor called" << std::endl;
	return ;
}

std::uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<std::uintptr_t>(ptr));
}

Data *Serializer::deserialize(std::uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
