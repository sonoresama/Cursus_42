/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:57:43 by eorer             #+#    #+#             */
/*   Updated: 2023/12/18 16:17:06 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
class	Array
{
  public:
	Array();
	Array(unsigned int n);
	Array(const Array& cpy);
	Array& operator=(const Array &cpy);
	~Array();

	void	_setValue(unsigned int i, T data);
	unsigned int	size(void);
	T& operator[](unsigned int i);
	class operatorException
	{
		const char* what() const throw();
	};

  private :
	T* _array;
	unsigned int _n;
};

#include "Array.tpp"
