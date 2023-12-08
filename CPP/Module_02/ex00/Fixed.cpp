/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:02:32 by eorer             #+#    #+#             */
/*   Updated: 2023/12/07 18:17:53 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _raw(0)
{
	std::cout << "Default constructor called" << std::endl;
	std::cout << Fixed::_fract << std::endl;
	std::cout << this->_raw << std::endl;
}

Fixed::Fixed(const Fixed &n)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_raw = n.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &f)
{
	this->_raw = f.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_raw);
}

void	Fixed::setRawBits(int const raw)
{
	this->_raw = raw;
}
