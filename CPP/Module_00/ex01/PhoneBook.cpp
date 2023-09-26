/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:26:50 by eorer             #+#    #+#             */
/*   Updated: 2023/09/26 18:44:07 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "main.hpp"

PhoneBook::PhoneBook(){
	std::cout << "Constructor called" << std::endl;
}

PhoneBook::~PhoneBook(){
	std::cout << "Destructor called" << std::endl;
}
