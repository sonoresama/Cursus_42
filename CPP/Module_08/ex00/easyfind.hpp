/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:32:59 by emileorer         #+#    #+#             */
/*   Updated: 2023/12/19 13:23:42 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class EasyFindException : public std::exception
{
	const char* what() const throw()
	{
		return ("No occurence found");
	}
};

template < typename T >
typename T::iterator	easyfind(T &container, int n);

#include "easyfind.tpp"
