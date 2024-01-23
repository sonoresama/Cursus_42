/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 00:16:08 by emileorer         #+#    #+#             */
/*   Updated: 2024/01/15 12:44:24 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Data.hpp"
#include <stdint.h>

class	Serializer
{
	public :
		Serializer();
		Serializer(const Serializer &cpy);
		Serializer &operator=(const Serializer &cpy);
		virtual ~Serializer() = 0;

		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};
