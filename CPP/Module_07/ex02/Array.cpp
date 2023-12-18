/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:19:10 by eorer             #+#    #+#             */
/*   Updated: 2023/12/18 15:21:00 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

Array::Array()
{
	std::cout << "Array default constructor called" << std::endl;
}

Array::Array(const Array &cpy)
{
	std::cout << "Array default constructor called" << std::endl;
}

Array &Array::operator=(const Array &cpy)
{
}

~Array::Array()
{
	std::cout << "Array default destructor called" << std::endl;
}
