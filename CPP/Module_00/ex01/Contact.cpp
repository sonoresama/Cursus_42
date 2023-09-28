/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:47:43 by eorer             #+#    #+#             */
/*   Updated: 2023/09/28 17:13:45 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Contact::Contact(){
}

Contact::~Contact(){
}

void Contact::init_contact(){
	std::cout << "Enter firstname : ";
	std::cin >> this->firstname;
	std::cout << "Enter lastname : ";
	std::cin >> this->lastname;
	std::cout << "Enter nickname : ";
	std::cin >> this->nickname;
	std::cout << "Enter number : ";
	std::cin >> this->number;
	std::cout << "Enter secret : ";
	std::cin >> this->dark_secret;
}

void Contact::print_infos(){
	std::cout << "Contact name : " << this->firstname << std::endl;
}
