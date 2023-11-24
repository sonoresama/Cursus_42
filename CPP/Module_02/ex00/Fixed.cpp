/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:58:52 by eorer             #+#    #+#             */
/*   Updated: 2023/10/04 16:46:41 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _raw(0){COUT("Default constructor called");}

Fixed::~Fixed(){COUT("Destructor called");}

Fixed::Fixed(const Fixed &f){
	this->_raw = f._raw;
	COUT("Copy constructor called");
}

Fixed& Fixed::operator=(Fixed const & rhs)
{
	this->_raw = rhs.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const {
	COUT("getRawBits member function called");
	return (this->_raw);
}

void Fixed::setRawBits(int const raw)
{
	this->_raw = raw;
}

