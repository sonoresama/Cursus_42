/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:57:43 by eorer             #+#    #+#             */
/*   Updated: 2023/12/18 15:17:47 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
class	Array
{
  public:
	Array();
	Array(const Array& cpy);
	Array& operator=(const Array &cpy);
	~Array();
};

#include "Array.tpp"
