/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 00:19:12 by emileorer         #+#    #+#             */
/*   Updated: 2023/12/17 19:24:34 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class	Data
{
	public :
		Data();
		Data(const Data &cpy);
		Data &operator=(const Data &cpy);
		~Data();

		int	getInt(void) const;
		std::string getStr(void) const;
	private :
		int i;
		std::string	str;
};
