/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:15:29 by emileorer         #+#    #+#             */
/*   Updated: 2024/01/15 12:44:33 by eorer            ###   ########.fr       */
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

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
