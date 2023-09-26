/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:47:43 by eorer             #+#    #+#             */
/*   Updated: 2023/09/26 18:56:55 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Contact::Contact(std::string x, std::string y, std::string z){
	prenom = x;
	nom = y;
	num = z;
	std::cout << "Contact constructor called" << std::endl;
}

Contact::~Contact(){
	std::cout << "Contact destructor called" << std::endl;
}
