/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 00:16:08 by emileorer         #+#    #+#             */
/*   Updated: 2023/12/17 19:26:55 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Data.hpp"

class	Serializer
{
	public :
		Serializer();
		Serializer(const Serializer &cpy);
		Serializer &operator=(const Serializer &cpy);
		virtual ~Serializer() = 0;

		static std::uintptr_t serialize(Data *ptr);
		static Data *deserialize(std::uintptr_t raw);
};
