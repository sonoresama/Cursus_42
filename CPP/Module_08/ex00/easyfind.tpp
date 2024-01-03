/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:45:50 by emileorer         #+#    #+#             */
/*   Updated: 2023/12/19 12:49:36 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template < typename T >
typename T::iterator	easyfind(T &container, int n)
{
	typename T::iterator it;
	for (it = container.begin(); it != container.end(); it++)
	{
		if (*it == n)
			return (it);
	}
	throw EasyFindException();
}
