/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:02:32 by eorer             #+#    #+#             */
/*   Updated: 2023/11/24 16:43:40 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// CONSTRUCTORS
Fixed::Fixed() : _number(0){COUT("Default constructor called");}

Fixed::Fixed(const int i_raw)
{
	COUT("Integer constructor called");
	this->_number = i_raw << this->_fract;
}

Fixed::Fixed(const float f_raw)
{
	COUT("Float constructor called");
	this->_number = roundf(f_raw * (1 << this->_fract));
}

Fixed::Fixed(const Fixed &n)
{
	COUT("Copy constructor called");
	this->_number = n.getRawBits();
}


// DESTRUCTOR
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


// PUBLIC METHODS
int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_number);
}

void	Fixed::setRawBits(int const raw)
{
	this->_number = raw;
}

float	Fixed::toFloat(void) const
{
	return((float)this->_number / (float)(1 << this->_fract));
}

int		Fixed::toInt(void) const
{
	return(this->_number >> this->_fract);
}


// SURCHARGES D'OPERATEURS
Fixed& Fixed::operator=(const Fixed &f)
{
	this->_number = f.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream &out, Fixed const &f)
{
	out << f.toFloat();
	return (out);
}

