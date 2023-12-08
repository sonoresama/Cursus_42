/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:02:32 by eorer             #+#    #+#             */
/*   Updated: 2023/12/07 16:19:52 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// CONSTRUCTORS
Fixed::Fixed() : _number(0)
{
//	COUT("Default constructor called");
}

Fixed::Fixed(const int i_raw)
{
//	COUT("Integer constructor called");
	this->_number = i_raw << this->_fract;
}

Fixed::Fixed(const float f_raw)
{
//	COUT("Float constructor called");
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
	//object level
int	Fixed::getRawBits(void) const
{
//	std::cout << "getRawBits member function called" << std::endl;
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
	//static
Fixed&	Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed&	Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() < b.toFloat())
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed &a, Fixed &b)
{
	if (a < b)
		return (b);
	return (a);
}

const Fixed&	Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() < b.toFloat())
		return (b);
	return (a);
}


// SURCHARGES D'OPERATEURS
	//assignation
Fixed& Fixed::operator=(const Fixed &f)
{
	if (this != &f)
		this->_number = f.getRawBits();
	return (*this);
}
	//bool
bool Fixed::operator>(const Fixed &f)
{
	if (this->_number > f.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed &f)
{
	if (this->_number < f.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed &f)
{
	if (this->_number >= f.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed &f)
{
	if (this->_number <= f.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed &f)
{
	if (this->_number == f.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed &f)
{
	if (this->_number != f.getRawBits())
		return (true);
	return (false);
}
	//operands
Fixed	Fixed::operator+(const Fixed &f)
{
	return (this->toFloat() + f.toFloat());
}

Fixed	Fixed::operator-(const Fixed &f)
{
	return (this->toFloat() - f.toFloat());
}

Fixed	Fixed::operator*(const Fixed &f)
{
	return (this->toFloat() * f.toFloat());
}

Fixed	Fixed::operator/(const Fixed &f)
{
	return (this->toFloat() / f.toFloat());
}
	//incrementations
Fixed &Fixed::operator++() //prefix
{
	this->_number++;
	return (*this);
}

Fixed Fixed::operator++(int) //suffix
{
	Fixed	tmp = *this;

	this->_number++;
	return (tmp);
}

Fixed &Fixed::operator--() //prefix
{
	this->_number--;
	return (*this);
}

Fixed Fixed::operator--(int) //suffix
{
	Fixed	tmp = *this;

	this->_number++;
	return (tmp);
}

std::ostream& operator<<(std::ostream &out, Fixed const &f)
{
	out << f.toFloat();
	return (out);
}
