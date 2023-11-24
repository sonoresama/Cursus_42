/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:58:52 by eorer             #+#    #+#             */
/*   Updated: 2023/10/04 19:31:55 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//CONSTRUCTEURS --------------------------
Fixed::Fixed() : _fixedPointNumber(0){
	COUT("Default constructor called");
}

Fixed::Fixed(const int integer){
	COUT("Integer constructor called");
	this->_fixedPointNumber = integer * (1 << this->_fixedPointPos);
}

Fixed::Fixed(const float floater){
	COUT("Floater constructor called");
	this->_fixedPointNumber = floater * (1 << this->_fixedPointPos);
}

Fixed::Fixed(const Fixed &f){
	COUT("Copy constructor called");
	this->_fixedPointNumber = f._fixedPointNumber;
}

//DESTRUCTEUR ----------------------------
Fixed::~Fixed(){
	COUT("Destructor called");
}

//FONCTIONS MEMBRES ----------------------
int Fixed::getRawBits(void) const {
	COUT("getRawBits member function called");
	return (this->_fixedPointNumber);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointNumber = raw;
}

int	Fixed::toInt(void) const
{
	return (this->_fixedPointNumber >> this->_fixedPointPos);
}

float Fixed::toFloat(void) const
{
	int	tmp;

	return (static_cast<float>(this->_fixedPointNumber) / static_cast<float>(1 << this->_fixedPointPos));
}

// SURCHARGES D'OPERATEURS ------------------
Fixed& Fixed::operator=(Fixed const & rhs)
{
	this->_fixedPointNumber = rhs.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream &out, Fixed const &rhs)
{
	out << rhs.toFloat();
	return (out);
}
