/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:19:10 by eorer             #+#    #+#             */
/*   Updated: 2023/12/18 16:04:39 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	std::cout << "Array default constructor called" << std::endl;
	this->_array = NULL;
}

template <typename T>
Array<T>::Array(unsigned int n) 
{
	std::cout << "Array size constructor called" << std::endl;
	this->_array = new T[n];
	this->_n = n;
}

template <typename T>
Array<T>::Array(const Array &cpy)
{
	std::cout << "Array default constructor called" << std::endl;
	*this = *cpy;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &cpy)
{
	if (cpy == *this)
		return (*this);
	this->_array = new T[cpy._n];
	for (unsigned int i = 0; i < cpy._n; i++)
		this->_array[i] = cpy._array[i];
	this->_n = cpy._n;
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	std::cout << "Array default destructor called" << std::endl;
	delete [] this->_array;
}

template <typename T>
void	Array<T>::_setValue(unsigned int i, T data)
{
	if (i >= this->_n || i < 0)
		throw Array::operatorException();
	this->_array[i] = data;
}

template <typename T>
unsigned int	Array<T>::size(void)
{
	return (this->_n);
}

template <typename T>
T&	Array<T>::operator[](unsigned int i)
{
	if (i >= this->_n || i < 0)
		throw Array::operatorException();
	return (this->_array[i]);
}

template <typename T>
const char*	Array<T>::operatorException::what() const throw()
{
	return ("Error: wrong index");
}
